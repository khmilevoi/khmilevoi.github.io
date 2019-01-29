import React, { Component } from "react";
import styled from "styled-components";

const Img = styled.img`
  width: 15px;
  height: 15px;
`;

export default class Icon extends Component {
  render() {
    return <Img src={this.props.src} />;
  }
}
