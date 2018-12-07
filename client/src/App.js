import React, { Component } from 'react';
import './App.css';
import axios from "axios";

import Particles from 'react-particles-js';


import Card from './Card'
import Mask from './Mask'
import Word from './Word'

const particlesOpt = {
  particles: {
    number: {
      value: 150,
      density: {
        enable: true,
        value_area: 800
      }
    }
  }
}

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      characters: [],
      masks: '',
      words: [],
      isClick: true
    }
    
    this.keyPressFunction = this.keyPressFunction.bind(this);
    this.getMask = this.getMask.bind(this);
  }
  
  async keyPressFunction(event) {
    if (event.charCode >= 97 && event.charCode <= 122 && document.activeElement.getAttribute('class') === 'App') {
      let char = String.fromCharCode(event.charCode);
      this.setState(prevState => ({
        characters: [...prevState.characters, char]
      }));
      console.log(this.state.characters.length);
    }else if (event.key == 'Enter') {
      let res = await axios.get(`${this.state.characters}?mask=${this.state.masks}`);
      this.setState({words: res.data.words});
    }else if (event.key == 'Backspace'  && this.state.isClick === true) {
      this.setState(prevState => ({
        characters: prevState.characters.slice(0,-1)
      }));
    }


  }

  getMask(masks){
    this.setState({masks:masks});
  }

  changeFocus = () => {
    this.setState({isClick: !this.state.isClick});
  }

  componentDidMount() {
    document.addEventListener('keyDown keyPress', this.keyPressFunction, false);
  }

  componentWillUnmount() {
    document.removeEventListener("keyDown keyPress", this.keyPressFunction, false)
  }

  style = {
    border: '3px solid green',
    padding: '10px',
    margin: 'auto',
    color: '#7C0A02',

    mask: {
      width:"90%", 
      justifyContent: "center", 
      alignItems: "center", 
      margin: "auto"
    }
  };

  render() {
    return (
   
      <div>
        <div className="App" onKeyPress={this.keyPressFunction} onKeyDown={this.keyPressFunction} tabIndex="0" onBlur={this.onBlur} onFocus={this.onFocus}>
          <div className="container-fluid">
            <div>
              {this.state.characters.map((char,key) =>
                <Card char={char} key={key}/>
              )}
            </div>
            <Mask getMask={this.getMask} changeFocus={this.changeFocus}/>
            <div style={{...this.style.mask}} className="container-fluid">
              {this.state.words.map((char,key) =>
                <Word char={char} key={key}/>
              )}
            </div>
          </div>
        </div>
        <Particles params={particlesOpt}/>  
      </div>     
    );
  }
}

export default App;
