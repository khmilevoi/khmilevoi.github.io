import React, { Component } from "react";
import styled from "styled-components";

import Text from "../Text";
import Link from "../Link";

import Icon from "./Icon";

const StateWrapper = styled.div`
  width: 100%;
  height: auto;
  display: flex;
  justify-content: space-between;
  align-items: center;
`;

const Left = styled.div`
  display: flex;
  padding: 5px;

  & > * {
    margin: 0 5px;
  }
`;

const Right = styled.div`
  display: flex;
  padding: 5px;

  & > * {
    margin: 0 10px;
  }
`;

const LikeIcon = styled.div`
  display: block;

  & > * {
    margin: 0 2.5px;
  }
`;

const CommentIcon = styled.div`
  display: block;

  & > * {
    margin: 0 2.5px;
  }
`;

const LikeSrc = process.env.PUBLIC_URL + "/img/Like.svg";
const CommentSrc = process.env.PUBLIC_URL + "/img/Comment.svg";

const Wrapper = styled.div`
  width: 100%;
  height: auto;
  padding: 15px 20px;
  display: flex;
  flex-direction: column;
`;

const CommentsWrapper = styled.div`
  display: flex;
  flex-direction: column;
  padding: 10px;
`;

const Comment = styled.div`
  display: flex;
  flex-direction: column;
  margin-bottom: 10px;
`;

const Top = styled.div`
  display: flex;
  margin-bottom: 10px;

  span {
    display: flex;
    align-items: flex-end;
    padding: 5px 10px 5px 0;
  }

  .header {
    font-size: 19px;
  }

  .description {
    font-size: 14px;
  }
`;

const Content = styled.div`
  background-color: #f2fbff;
  border: 1.5px solid #d5d5d5;
  padding: 20px;
  position: relative;

  &:before {
    content: "";
    display: block;
    width: 0;
    height: 0;
    border: 7px solid red;
    border-color: transparent transparent #d5d5d5 #d5d5d5;
    position: absolute;
    top: 0;
    margin: -14px 0 0 0;
  }

  &:after {
    content: "";
    display: block;
    width: 0;
    height: 0;
    border: 5px solid red;
    border-color: transparent transparent #f2fbff #f2fbff;
    position: absolute;
    top: 0;
    margin: -10px 0 0 1.5px;
  }
`;

const FormWrapper = styled.form`
  width: calc(100% + 40px);
  margin-left: -20px;
  display: flex;
  align-items: center;
  flex-direction: column;
  padding: 20px 30px;
  background-color: #f2f2f2;

  & > * {
    margin: 10px 0;
  }
`;

const Input = styled.input`
  width: 100%;
  background-color: white;
  border: 1.5px solid #a9a9a9;
  border-radius: 1px;
  padding: 10px 15px;
`;

const Textarea = styled.textarea`
  width: 100%;
  background-color: white;
  border: 1.5px solid #a9a9a9;
  border-radius: 1px;
  padding: 10px 15px;
  resize: none;
`;

const Button = styled.button`
  width: 280px;
  padding: 15px;
  background-color: #fdd639;
  border: none;
  outline: none;
  border-radius: 100px;
  cursor: pointer;

  span {
    font-size: 16px;
  }
`;

const comments = [
  {
    name: "Самуил",
    date: "13 октября 2011",
    text: "Привет, Верунь! ниче себе ты крутая. фотка класс!!!!"
  },
  {
    name: "Лилия Семёновна",
    date: "14 октября 2011",
    text:
      "Вероника, здравствуйте! Есть такой вопрос: Особый вид куниц жизненно стабилизирует кинетический момент, это и есть всемирно известный центр огранки алмазов и торговли бриллиантами?"
  },
  {
    name: "Лилия Семёновна",
    date: "14 октября 2011",
    text:
      "Вероника, здравствуйте! Есть такой вопрос: Особый вид куниц жизненно стабилизирует кинетический момент?"
  },
  {
    name: "Темчур Карина",
    date: "14 октября 2011",
    text:
      "Вероника, здравствуйте! Есть такой вопрос: Особый вид куниц жизненно стабилизирует кинетический момент?"
  },
  {
    name: "Хмилевой Алексей",
    date: "14 октября 2011",
    text:
      "Вероника, здравствуйте! Есть такой вопрос: Особый вид куниц жизненно стабилизирует кинетический момент?"
  }
];

export default class Reviews extends Component {
  constructor(props) {
    super(props);

    this.state = {
      show: false,
      name: "",
      text: ""
    };

    this.showComments = this.showComments.bind(this);
    this.updateName = this.updateName.bind(this);
    this.updateMessage = this.updateMessage.bind(this);
    this.updateComment = this.updateComment.bind(this);
  }

  showComments(event) {
    event.preventDefault();
    this.setState({
      show: !this.state.show
    });
  }

  getComments() {
    return this.state.show ? comments : comments.slice(-3);
  }

  renderComments() {
    return this.getComments().map((item, index) => (
      <Comment key={index}>
        <Top>
          <Text class="header" text={item.name} />
          <Text class="description" text={item.date} />
        </Top>
        <Content>
          <Text class="text" text={item.text} />
        </Content>
      </Comment>
    ));
  }

  updateComment() {
    var months = [
      "Январь",
      "Февраль",
      "Март",
      "Апрель",
      "Май",
      "Июнь",
      "Июль",
      "Август",
      "Сентябрь",
      "Ноябрь",
      "Декабрь"
    ];

    var now = new Date();

    var date = `${now.getDate()} ${
      months[now.getMonth()]
    } ${now.getFullYear()}`;

    var comment = {
      name: this.state.name,
      text: this.state.text,
      date: date
    };

    this.setState({
      name: "",
      text: ""
    });

    if (comment.name !== "" && comment.text !== "") {
      comments.push(comment);
    }
  }

  updateName(event) {
    this.setState({
      name: event.target.value
    });
  }

  updateMessage(event) {
    this.setState({
      text: event.target.value
    });
  }

  render() {
    return (
      <Wrapper>
        <StateWrapper className="StateWrapper">
          <Left>
            <Text class="header" text="Последние отзывы" />
            <Link
              class="showComments"
              href="#"
              text="Все отзывы"
              onClick={this.showComments}
            />
          </Left>

          <Right>
            <LikeIcon>
              <Icon src={LikeSrc} />
              <Text class="text" text="131" />
            </LikeIcon>
            <CommentIcon>
              <Icon src={CommentSrc} />
              <Text class="text" text={comments.length} />
            </CommentIcon>
          </Right>
        </StateWrapper>

        <CommentsWrapper>{this.renderComments()}</CommentsWrapper>

        <FormWrapper>
          <Input placeholder="Введите имя" onChange={this.updateName} />
          <Textarea
            placeholder="Ваше сообщение"
            onChange={this.updateMessage}
            onKeyDown={event => {
              var key = event || window.event;

              if (key.keyCode === 13 && key.ctrlKey) {
                this.updateComment();
              }
            }}
          />
          <Button type="reset" onClick={this.updateComment}>
            <Text class="header" text="Написать консультанту" />
          </Button>
        </FormWrapper>
      </Wrapper>
    );
  }
}
