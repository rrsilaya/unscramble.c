import React, { Component } from 'react'

class Word extends Component {
    style = {
        card: {
            display: "inline-block",
            margin: ".5em .25em",
            backgroundColor: "#379683",
            borderRadius: "10px",
            width: "8em",
        },
        heading: {
            fontSize: "2rem",
            width: "5rem",
            height: "2rem"
        }
    }
    render() {
        return(
            <div className="card text-center" style={{...this.style.card}}>
                <div className="card-body">
                    <h6 style={{fontWeight: "bold"}}>{this.props.char}</h6>
                </div>
            </div>
        )
    }
}

export default Word;