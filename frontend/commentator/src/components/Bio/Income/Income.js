import React, { Component } from "react";
import styled from "styled-components";

import Text from "../../Text";

const Subject = styled.div`
  width: ${props => props.dataWidth}%;
  border-radius: 0 5px 5px 0;
  padding: 5px;
  border-left: 2px solid
    ${props => (props.highlight === "true" ? "#94BD81" : "#90BFD1")};
  background-color: ${props =>
    props.highlight === "true" ? "#B1E19B" : "#ACE2F8"};

  span {
    white-space: nowrap;
  }
`;

export default class Income extends Component {
  constructor(props) {
    super(props);

    props.data.sort((left, right) => {
      return right[1] - left[1];
    });

    this.state = {
      subjects: this.props.data
    };
  }

  renderSubjects() {
    return this.state.subjects.map((item, index) => (
      <tr key={index}>
        <td>
          <Subject
            highlight={item[1] === this.getMax() ? "true" : "false"}
            dataWidth={(100 * item[1]) / this.getMax()}
          >
            <Text clas="text" text={item[0]} />
          </Subject>
        </td>
        <td>
          <Text clas="text" text={item[1]} />
        </td>
      </tr>
    ));
  }

  getSum() {
    var sum = 0;

    for (let index = 0; index < this.state.subjects.length; ++index) {
      sum += this.state.subjects[index][1];
    }

    return sum;
  }

  getMax() {
    var max = 0;

    for (let index = 0; index < this.state.subjects.length; ++index) {
      if (max < this.state.subjects[index][1]) {
        max = this.state.subjects[index][1];
      }
    }

    return max;
  }

  render() {
    return (
      <table className="IncomeTable">
        <tbody>
          <tr>
            <td />
            <td>
              <Text class="text" text="Услуг" />
            </td>
          </tr>

          {this.renderSubjects()}

          <tr>
            <td>
              <Text class="header" text="Всего" />
            </td>
            <td>
              <Text class="header" text={this.getSum()} />
            </td>
          </tr>
        </tbody>
      </table>
    );
  }
}
