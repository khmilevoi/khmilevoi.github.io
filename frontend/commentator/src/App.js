import React, { Component } from "react";
import styled from "styled-components";
import "./App.css";

import Bio from "./components/Bio/Bio";
import Reviews from "./components/Reviews/Reviews";

const Wrapper = styled.div`
  width: 100%;
  max-width: 720px;
  min-width: 360px;
  height: auto;
  display: flex;
  flex-direction: column;
  background-color: #ffffff;
`;

export default class App extends Component {
  render() {
    return (
      <Wrapper>
        <Bio />
        <Reviews />
      </Wrapper>
    );
  }
}
