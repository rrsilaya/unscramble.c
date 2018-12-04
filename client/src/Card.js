import React, { Component } from 'react'

class Card extends Component {
    style = {
        card: {
            width: "6rem",
            height: "8rem",
            display: "inline-block",
            margin: ".5em .5em",
            backgroundColor: "#05386B",
            borderRadius: "15px" 
        },
        heading: {
            fontSize: "5em",
            fontWeight: "bold"
        }
    }
    render() {
        return(
            <div className="card text-center text-white" style={{...this.style.card}}>
                <div className="card-body">
                    <h1 style={{...this.style.heading}}>{this.props.char}</h1>
                </div>
            </div>
        )
    }
}

export default Card;