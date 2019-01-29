import React, { Component } from "react";
import styled from "styled-components";

const Img = styled.img`
  width: 120px;
  height: 120px;
  border-radius: 60px;
  object-fit: cover;
  z-index: 11;
`;

export default class Foto extends Component {
  render() {
    return <Img src={this.props.src} />;
  }
}
