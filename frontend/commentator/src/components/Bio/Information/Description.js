import React, { Component } from "react";
import styled from "styled-components";

import Text from "../../Text";

const DescriptionWrapper = styled.div`
  width: 100%;
  height: 50%;
  border: 1.5px solid #dddace;
  border-radius: 5px;
  background-color: #fffbc8;
  padding: 10px 15px 10px 70px;
  margin-left: -60px;
  z-index: 10;
`;

export default class Description extends Component {
  render() {
    return (
      <DescriptionWrapper className="DescriptionWrapper">
        <Text
          class="text"
          text="Подберу для вас самые лучшие предложения. Мои услуги абсолютно бесплатны"
        />
      </DescriptionWrapper>
    );
  }
}
