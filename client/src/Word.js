import React, { Component } from 'react'

class Word extends Component {
    style = {
        card: {
            display: "inline-block",
            margin: ".5em .25em",
            backgroundColor: "#05386B",
            borderRadius: "10px",
            maxWidth: "100%"
        },
        heading: {
            fontSize: "3.5vw",
            width: "5rem",
            height: "2rem",
            color: "white"
        }
    }
    render() {
        return (
            <div className="card text-center text-white" style={{ ...this.style.card }}>
                <div className="card-body" style={{ maxWidth: "100%" }}>
                    <h6 style={{ fontWeight: "bold" }}>{this.props.char}</h6>
                </div>
            </div>
        )
    }
}

export default Word;