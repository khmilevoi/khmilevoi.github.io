import React, { Component } from "react";
import styled from "styled-components";

import Foto from "./Information/Foto";
import Text from "../Text";
import Description from "./Information/Description";

import Income from "./Income/Income";

const Wrapper = styled.div`
  width: 100%;
  height: auto;
  display: flex;
  flex-direction: column;
`;

const InformationWrapper = styled.div`
  width: 100%;
  height: auto;
  padding: 15px 20px;
  display: flex;
`;

const TextWrapper = styled.div`
  width: calc(100% - 120px);
  display: flex;
  flex-direction: column;
  padding: 0 0 10px 0;
`;

const NameAndPosition = styled.div`
  height: 50%;
  display: flex;
  flex-direction: column;
  justify-content: space-around;
  margin-bottom: 5px;
  margin-left: 10px;
`;

const IncomeWrapper = styled.div`
  width: calc(100% - 150px);
  height: auto;
  margin: 0 20px 10px 130px;
`;

const src = process.env.PUBLIC_URL + "/img/face.png";

const data = [
  ["Ручное бронирование", 11],
  ["Пакетные туры", 3],
  ["Отели", 1],
  ["Экскурии", 10]
];

export default class Bio extends Component {
  render() {
    return (
      <Wrapper>
        <InformationWrapper>
          <Foto src={src} />
          <TextWrapper>
            <NameAndPosition>
              <Text class="header" text="Вероника Ростtова" />
              <Text class="description" text="Менеджер по продажам" />
            </NameAndPosition>
            <Description />
          </TextWrapper>
        </InformationWrapper>
        <IncomeWrapper className="IncomeWrapper">
          <Income data={data} />
        </IncomeWrapper>
      </Wrapper>
    );
  }
}
