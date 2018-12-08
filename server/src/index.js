const express = require('express');
const bodyParser = require('body-parser');

const util = require('util');
const exec = util.promisify(require('child_process').exec);

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

const throwError = (res, error) => {
  return res.status(error.code).json(error.payload);
}

app.use('/api/:letters', async (req, res) => {
  const { letters } = req.params;

  if (/[A-Za-z]+/.test(letters) && letters.length < 50) {
    const { mask = Array.from({ length: letters.length }).reduce(acc => acc + '_', '') } = req.query

    if (/[A-Za-z_]+/.test(mask) && mask.length < 50) {
      try {
        const { stdout } = await exec(`./bin/unscramble.exe ${letters} ${mask}`);
        
        const words = stdout.split('\n');
        words.pop();
        const [, time] = words.pop().match(/(\d+)ms/);

        return res.status(200).json({
          words: words,
          letters,
          mask,
          time: +time,
        });
      } catch(err) {
        return throwError(res, {
          code: 400,
          payload: { message: 'Invalid mask input', letters, mask }
        });
      }
    }
  } else {
    return throwError(res, {
      code: 400,
      payload: { message: 'Invalid letter input', letters, mask }
    });
  }
});

app.use(express.static(__dirname + '/../public/'));
app.use('*', (req, res) => res.redirect('/'));

const port = process.env.PORT || 3001;
app.listen(port, () => {
  console.log(`Server listening to port ${port}`);
});
