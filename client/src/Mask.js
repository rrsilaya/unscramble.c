

import React, { Component } from 'react'
import "./Mask.css"

class Mask extends Component {
    constructor(props) {
        super(props);
        this.state = {
            masks: [],
            focused: false,
            input: ''
        }
        this.keyPressFunction = this.keyPressFunction.bind(this)
    }
      
    keyPressFunction(event) {
        let char = String.fromCharCode(event.charCode);
        this.setState(prevState => ({
            masks: [...prevState.masks, char]
        }));
    }

    onTypeMaster = (length) => {
        var i;
        let char = '';
        for (i = 0; i < length + 1; i++) {
            char += '_'; 
        }
        this.setState({input: char}, () => {this.props.getMask(this.state.input)});
    }
     
    updateInputValue = (e) => {
        this.setState({
            input: e.target.value
        })
        this.props.getMask(e.target.value)
    }
    
    render() {
        return(
            <div className="wrapper" tabIndex="0">
                <input 
                    ref="mask" 
                    className="input" 
                    placeholder="Add mask" 
                    type="text" 
                    value={this.state.input}
                    onKeyPress={this.keyPressFunction}
                    onChange={this.updateInputValue} 
                    onFocus={this.props.changeFocus}
                    onBlur={this.props.changeFocus}
                />
                <span className="underline"></span>
            </div>

        )
    }
}

export default Mask;