function insertAfter(elem, refElem) {
  var parent = refElem.parentNode;
  var next = refElem.nextSibling;
  if (next) {
    return parent.insertBefore(elem, next);
  } else {
    return parent.appendChild(elem);
  }
}

String.prototype.replaceAll = function(search, replace) {
  return this.split(search).join(replace);
};

String.prototype.normalizeName = function() {
  return this[0].toUpperCase() + this.slice(1).toLowerCase();
};

function update_analysis() {
  top_airlines();
  top_airport();
  flight_congestion();
  employee_performance();
}

window.onload = () => {
  check_active_div();
  filling_arrays();
  show_table("khmilevoi_airports");
  update_analysis();
};

function filling_select(data) {
  let arr;

  let tables = document.getElementById("select-table");

  if (tables.childElementCount == 0) {
    arr = arrays[5];
    for (let table = 0; table < arr.length; ++table) {
      let option = document.createElement("option");
      option.value = arr[table];

      let text = document.createTextNode(
        arr[table][0].toUpperCase() + arr[table].slice(1).toLowerCase()
      );

      option.appendChild(text);

      tables.appendChild(option);
    }
  }
}

function alert(text) {
  let alert = document.createElement("div");
  alert.className += "alert";
  alert.textContent = text;
  alert.style.display = "block";
  alert.style.bottom =
    (alert.offsetHeight + 60) *
      document.getElementsByClassName("alert").length +
    "px";

  document.body.appendChild(alert);

  setTimeout(() => {
    document.body.removeChild(alert);
  }, 5000);
}

setInterval(() => {
  let forms = document.getElementsByTagName("form");
  for (let index = 0; index < forms.length; ++index) {
    forms[index].onsubmit = () => {
      return false;
    };
  }

  let login = document.getElementsByClassName("pop-up-autorization")[0];

  if (
    user.state == state_of_ineterface.li &&
    user.state_of_interface == state_of_ineterface.nli
  ) {
    login.className = login.className.replace(" locked", "");

    user.state_of_interface = state_of_ineterface.li;

    document.getElementsByClassName(
      "users-name"
    )[0].children[0].children[0].innerHTML = user.login;
  } else if (
    (user.state == state_of_ineterface.nli &&
      user.state_of_interface == state_of_ineterface.li) ||
    (user.state == state_of_ineterface.nli &&
      user.state_of_interface == state_of_ineterface.nli)
  ) {
    if (login.className.indexOf("locked") < 0) {
      login.className += " locked";
    }
    user.reset();
  }
}, 500);

document.getElementById("btn-login").addEventListener("click", event => {
  // event.preventDefault();

  let login = document.getElementById("login-login").value;
  let password = document.getElementById("login-password").value;

  if (login == "" || password == "") {
    alert("Заполните все поля");
    return;
  }

  autorization_admin(login, password);
});

document.getElementById("sign-out").addEventListener("click", event => {
  event.preventDefault();

  user.reset();

  alert("Вы вышли");
});

let menu_items = document.getElementsByClassName("nav-div")[0].children;

for (let index = 0; index < menu_items.length; ++index) {
  menu_items[index].addEventListener("click", event => {
    event.preventDefault();

    for (let item = 0; item < menu_items.length; ++item) {
      if (item == index) {
        if (menu_items[item].className.indexOf("active") < 0) {
          menu_items[item].className += " active";
        }
      } else {
        menu_items[item].className = menu_items[item].className.replace(
          " active",
          ""
        );
      }
    }

    check_active_div();

    update_analysis();
  });
}

function check_active_div() {
  let menu_items = document.getElementsByClassName("nav-div")[0].children;
  let contents = document.getElementsByClassName("content-div")[0].children;

  for (let index = 0; index < menu_items.length; ++index) {
    if (
      menu_items[index].className.indexOf("active") >= 0 &&
      contents[index].className.indexOf("active") < 0
    ) {
      contents[index].className += " active";
    } else if (menu_items[index].className.indexOf("active") < 0) {
      contents[index].className = contents[index].className.replace(
        " active",
        ""
      );
    }
  }
}

document.getElementById("select-table").addEventListener("click", event => {
  let table_name = document.getElementById("select-table").value;
  show_table(table_name);
});

var current_table;

function update_table(result) {
  current_table = result;

  var data = result.data;

  var tbl_body = document.createElement("tbody");

  for (let index = -1; index < data["rows"].length; index++) {
    let row = document.createElement("tr");

    for (let index2 = 0; index2 < data.fields.length + 2; ++index2) {
      if (index >= 0 && index2 == data.fields.length) {
        var cell = document.createElement("td");

        cell.className += "edit";

        var button = document.createElement("button");

        button.innerHTML = `<img src="./img/edit.svg"></img>`;

        button.addEventListener("click", event => {
          var td = document.getElementsByClassName("edit")[index];

          var parent = td.parentElement;

          var id = parent.children[0].innerText;

          for (
            let children = 1;
            children < parent.childElementCount - 2;
            ++children
          ) {
            if (data.fields[children].name.indexOf("date") >= 0) {
              parent.children[
                children
              ].innerHTML = `<input type='datetime-local' value='${
                parent.children[children].innerHTML.split(".")[0]
              }'>`;
            } else {
              parent.children[
                children
              ].innerHTML = `<input type='text' value='${
                parent.children[children].innerHTML
              }'>`;
            }
          }

          var ok = document.createElement("button");

          ok.innerHTML = `<img src="./img/ok.svg"></img>`;

          ok.addEventListener("click", event => {
            let updates = [];

            updates.push(id);

            for (
              let children = 1;
              children < parent.childElementCount - 2;
              ++children
            ) {
              updates.push(parent.children[children].children[0].value);

              if (parent.children[children].children[0].value == "") {
                alert("Заполните поля");
                return;
              }
            }

            var fields = [];

            for (let el = 0; el < data.fields.length; ++el) {
              fields.push(data.fields[el].name);
            }

            update_cortege(result.table_name, fields, updates);
          });

          cell.className.replace("edit", "ok");

          parent.children[parent.childElementCount - 2].innerHTML = "";
          parent.children[parent.childElementCount - 2].appendChild(ok);
        });

        cell.appendChild(button);
      } else if (index >= 0 && index2 == data.fields.length + 1) {
        var cell = document.createElement("td");

        cell.className += "delete";

        var button = document.createElement("button");

        button.innerHTML = `<img src="./img/delete.svg"></img>`;

        button.addEventListener("click", event => {
          var td = document.getElementsByClassName("delete")[index];

          var parent = td.parentElement;

          var id = parent.children[0].innerText;

          var ok = document.createElement("button");

          ok.innerHTML = `<img src="./img/ok.svg"></img>`;

          cell.className.replace("delete", "ok");

          ok.addEventListener("click", event => {
            delete_cortege(result.table_name, data.fields[0].name, id);
          });

          parent.children[parent.childElementCount - 1].innerHTML = "";
          parent.children[parent.childElementCount - 1].appendChild(ok);
        });

        cell.appendChild(button);
      } else if (index2 <= data.fields.length) {
        if (index2 < data.fields.length) {
          if (index < 0) {
            var cell = document.createElement("th");
            var cellText = document.createTextNode(
              data.fields[index2].name.replaceAll("_", " ")
            );
          } else {
            var cell = document.createElement("td");

            if (
              result.table_name == "khmilevoi_order" &&
              data.fields[index2].name == "number_of_order"
            ) {
              var cellText = document.createElement("a");

              cellText.href = "#";

              cellText.className += "pas-link";

              cellText.innerHTML = `${
                data["rows"][index][data.fields[index2].name]
              }`;

              cellText.addEventListener("click", event => {
                get_passenger(data["rows"][index][data.fields[index2].name]);
              });
            } else {
              var cellText = document.createTextNode(
                data["rows"][index][data.fields[index2].name]
              );
            }
          }
        } else {
          if (index < 0) {
            var cell = document.createElement("th");

            cell.className += "add";

            var cellText = document.createElement("button");

            cellText.innerHTML = `<img src="./img/add.svg"></img>`;

            cellText.addEventListener("click", event => {
              var new_row = document.createElement("tr");

              new_row.appendChild(document.createElement("td"));

              for (let input = 1; input < data.fields.length + 1; ++input) {
                var new_cell = document.createElement("td");

                if (input < data.fields.length) {
                  new_cell.innerHTML = "<input type='text'>";

                  if (data.fields[input].name.indexOf("date") >= 0) {
                    new_cell.innerHTML = `<input type='datetime-local' >`;
                  } else {
                    new_cell.innerHTML = `<input type='text'>`;
                  }
                } else {
                  var ok = document.createElement("button");

                  ok.innerHTML = `<img src="./img/ok.svg"></img>`;

                  new_cell.className += "ok";

                  ok.addEventListener("click", event => {
                    var new_data = [];
                    var fields = [];

                    for (let el = 1; el < data.fields.length; ++el) {
                      let val = new_row.children[el].children[0].value;

                      if (val == "") {
                        alert("Заполните все поля");
                        return;
                      }

                      fields.push(data.fields[el].name);
                      new_data.push(val);
                    }

                    add_cortege(result.table_name, fields, new_data);
                  });

                  new_cell.appendChild(ok);
                }

                new_row.appendChild(new_cell);
              }

              insertAfter(new_row, tbl_body.children[0]);
            });
          }
        }

        cell.appendChild(cellText);
      }

      row.appendChild(cell);
    }

    tbl_body.appendChild(row);
  }

  document.getElementsByClassName("show-table")[0].innerHTML = "";
  document.getElementsByClassName("show-table")[0].appendChild(tbl_body);
}

document.getElementById("show-updates").addEventListener("click", event => {
  var pop_up = document.getElementsByClassName("pop-up-updates")[0];

  if (pop_up.className.indexOf("locked") < 0) {
    pop_up.className += " locked";
  }

  show_updates(user.login);
});

document.getElementById("show-diagram").addEventListener("click", event => {
  var pop_up = document.getElementsByClassName("pop-up-diagram")[0];

  if (pop_up.className.indexOf("locked") < 0) {
    pop_up.className += " locked";
  }
});

document
  .getElementById("close-btn-updates")
  .addEventListener("click", event => {
    var pop_up = document.getElementsByClassName("pop-up-updates")[0];

    if (pop_up.className.indexOf("locked") >= 0) {
      pop_up.className = pop_up.className.replace(" locked", "");
    }
  });

document
  .getElementById("close-btn-diagram")
  .addEventListener("click", event => {
    var pop_up = document.getElementsByClassName("pop-up-diagram")[0];

    if (pop_up.className.indexOf("locked") >= 0) {
      pop_up.className = pop_up.className.replace(" locked", "");
    }
  });

function show_update_table(result) {
  var tbl_body = document.createElement("tbody");

  for (let index = 0; index < result["rows"].length; index++) {
    let row = document.createElement("tr");

    for (let index2 = 0; index2 < result.fields.length; ++index2) {
      var cell = document.createElement("td");
      let str = `${result["rows"][index][result.fields[index2].name]}`;
      var cellText = document.createTextNode(
        str
          .replaceAll(`"`, " ")
          .replaceAll("T", " ")
          .replaceAll("Z", " ")
      );
      cell.appendChild(cellText);
      row.appendChild(cell);
    }

    tbl_body.appendChild(row);
  }

  document.getElementById("table-updates").innerHTML = "";
  document.getElementById("table-updates").appendChild(tbl_body);
}

document.getElementById("btn-table-search").addEventListener("click", event => {
  var table_name = current_table.table_name;

  var fields = [];

  for (let field = 0; field < current_table.data.fields.length; ++field) {
    fields.push(current_table.data.fields[field].name);
  }

  var search_tag = document.getElementById("table-search-input").value;

  search_on_table(table_name, fields, search_tag);
});

function update_list(response) {
  var data = response.data;
  var name = response.name;

  var list;

  if (name == message_type.top_airlines) {
    list = document.getElementsByClassName("top-airlines")[0];
  }

  if (name == message_type.top_airport) {
    list = document.getElementsByClassName("top-airport")[0];
  }

  if (name == message_type.flight_congestion) {
    list = document.getElementsByClassName("flight-congestion")[0];
  }

  if (name == message_type.employee_performance) {
    list = document.getElementsByClassName("employee-performance")[0];
  }

  drawShedule(response);

  list.innerHTML = "";

  if (name != message_type.flight_congestion) {
    for (let index = 0; index < data.rows.length; ++index) {
      var li = document.createElement("li");

      li.textContent = `${data.rows[index].count} ${data.rows[
        index
      ].name.normalizeName()} `;

      list.appendChild(li);
    }
  } else {
    for (let index = 0; index < data.rows.length; ++index) {
      var li = document.createElement("li");

      li.innerHTML = `
        ${
          data.rows[index].name
        } <div class='procent-wrapper'><div class='procent' style="width:${Math.round(
        (data.rows[index].count * 100) / data.rows[index].number_of_seates
      )}%;">${data.rows[index].count}/${
        data.rows[index].number_of_seates
      }</div></div>
      `;

      list.appendChild(li);
    }
  }
}

function drawShedule(response) {
  var shedules = document.getElementsByClassName("schedule");

  var shedule = 0;

  if (response.name == message_type.top_airlines) {
    shedule = 0;
  } else if (response.name == message_type.top_airport) {
    shedule = 1;
  } else if (response.name == message_type.flight_congestion) {
    shedule = 2;
  } else if (response.name == message_type.employee_performance) {
    shedule = 3;
  }

  shedules[shedule].width = shedules[shedule].offsetWidth * 2;
  shedules[shedule].height = shedules[shedule].offsetHeight * 2;

  var TO_RADIANS = Math.PI / 180;
  var canvas = shedules[shedule];
  var context = canvas.getContext("2d");
  var width = shedules[shedule].width;
  var height = shedules[shedule].height;

  context.clearRect(0, 0, width, height);

  var cell = width / response.data.rowCount;

  var max = 0;

  for (let index = 0; index < response.data.rowCount; ++index) {
    if (
      response.name == message_type.top_airlines ||
      response.name == message_type.top_airport ||
      response.name == message_type.employee_performance
    ) {
      for (let index = 0; index < response.data.rowCount; ++index) {
        if (max < response.data.rows[index].count) {
          max = Number(response.data.rows[index].count);
        }
      }

      var size = (response.data.rows[index].count * height) / max;
    } else if (response.name == message_type.flight_congestion) {
      var size =
        (response.data.rows[index].count * height) /
        response.data.rows[index].number_of_seates;
    }

    size += cell / 2;

    size = size >= height ? height : size;

    context.fillStyle = "#5B9D32";
    context.fillRect(cell * index, height - size, cell, size);

    context.rotate(TO_RADIANS * 90);

    context.font = `30px Arial`;
    context.fillStyle = "#144c0d";
    context.fillText(
      response.data.rows[index].name,
      10,
      -cell * index - cell / 2 + 10
    );

    context.rotate(TO_RADIANS * -90);
  }
}

document.getElementById("refresh-icon").addEventListener("click", () => {
  update_analysis();
});
