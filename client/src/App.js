import React, { Component } from 'react';
import './App.css';

class App extends Component {
  style = {
    border: '3px solid green',
    padding: '10px',
    margin: 'auto',
    color: '#7C0A02'
  }

  render() {
    return (
      <div className="App">
        <form>
          <div className="card" style={{...this.style}}>
            <img className="card-img-top" src="..." alt="*found words here*"/>
            <div className="card-body" style={{width: '100%'}}>
              <p className="card-text">words words words words words words words</p>
            </div>
            <div className="form-row">
              <div className="col">
                <input type="text" className="form-control" placeholder="Characters"/>
              </div>
              <div className="col">
                <input type="text" className="form-control" placeholder="Mask"/>
              </div>
              <button type="button" className="btn btn-outline-success">Solve</button>
            </div>
          </div>
        </form>
      </div>
    );
  }
}

export default App;
