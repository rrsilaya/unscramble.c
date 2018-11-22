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

  if (/[A-Za-z]+/.test(letters) && letters.length < 40) {
    const { mask = Array.from({ length: letters.length }).reduce(acc => acc + '_', '') } = req.query

    if (/[A-Za-z_]+/.test(mask) && mask.length < 40) {
      try {
        const { stdout } = await exec(`./bin/unscramble.exe ${letters} ${mask}`);
        
        const words = stdout.split('\n');

        return res.status(200).json({
          words: words.slice(0, words.length - 1),
          letters,
          mask,
        });
      } catch(err) {
        return throwError(res, {
          code: 403,
          payload: { message: 'Invalid mask input', letters, mask }
        });
      }
    }
  } else {
    return throwError(res, {
      code: 403,
      payload: { message: 'Invalid letter input', letters, mask }
    });
  }
});

const port = process.env.PORT || 3001;
app.listen(port, () => {
  console.log(`Server listening to port ${port}`);
});
