import React, { Component } from "react";
import styled from "styled-components";

const Ancer = styled.a`
  font-size: 16px;
  color: #156aa9;
  text-decoration: none;
  transition: none;
  line-height: 27px;

  &:hover {
    text-decoration: underline;
  }
`;

export default class Link extends Component {
  render() {
    return (
      <Ancer className={this.props.class || ""} onClick={this.props.onClick} href={this.props.href}>
        {this.props.text}
      </Ancer>
    );
  }
}
