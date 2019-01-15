const message_type = {
  autorization_admin: "autorization_admin",
  autorization_user: "autorization_user",
  update_countries: "update_countries",
  update_airports: "update_airports",
  update_airlines: "update_airlines",
  update_classes: "update_classes",
  update_age_categories: "update_age_categories",
  update_rate: "update_rate",
  buying_of_ticket: "buying_of_ticket",
  filling_arrays: "filling_arrays",
  get_cost: "get_cost",
  show_orders: "show_orders",
  show_flights: "show_flights",
  registration_user: "registration_user",
  show_table: "show_table",
  get_passenger: "get_passenger",
  update_cortege: "update_cortege",
  show_updates: "show_updates",
  delete_cortege: "delete_cortege",
  add_cortege: "add_cortege",
  search_on_table: "search_on_table",
  top_airlines: "top_airlines",
  top_airport: "top_airport",
  flight_congestion: "flight_congestion",
  employee_performance: "employee_performance"
};

const use = {
  admin: "admin",
  usual: "usual",
  any: "any"
};

const type_of_user = {
  admin: "admin",
  usual: "usual"
};

const state_of_ineterface = {
  li: "loged in",
  nli: "not loged in"
};

class User {
  constructor() {
    this.login = "Anonimus";
    this.firstname = "";
    this.lastname = "";
    this.phone = "";
    this.email = "";
    this.pasport_id = "";
    this.password = "";
    this.type_of_user = type_of_user.usual;
    this.state = state_of_ineterface.nli;
    this.state_of_interface = state_of_ineterface.nli;
  }

  reset() {
    this.login = "Anonimus";
    this.firstname = "";
    this.lastname = "";
    this.phone = "";
    this.email = "";
    this.pasport_id = "";
    this.password = "";
    this.type_of_user = type_of_user.usual;
    this.state = state_of_ineterface.nli;
    this.state_of_interface = state_of_ineterface.nli;
  }
}
let user = new User();
let arrays = [];

const HOST = location.origin.replace(/^http/, "ws");

const ws = new WebSocket("ws://localhost:3000");

ws.onopen = () => {
  console.log("Online");
};

ws.onclose = () => {
  console.log("Diconnected");
};

ws.onmessage = res => {
  if (res != "undefined" && res.data != "") {
    res = JSON.parse(res.data);
    console.log(res);

    if (res.name == message_type.filling_arrays) {
      for (let index = 0; index < res.data.length; ++index) {
        let cash = [];
        let tmp = res.data[index];
        for (let index2 = 0; index2 < tmp.rows.length; ++index2) {
          cash.push(tmp.rows[index2][tmp.fields[0].name]);
        }
        arrays.push(cash);
      }
      filling_select(arrays);
    }

    if (
      res.name == message_type.top_airlines ||
      res.name == message_type.top_airport ||
      res.name == message_type.flight_congestion ||
      res.name == message_type.employee_performance
    ) {
      update_list(res);
    }

    if (res.name == message_type.show_updates) {
      show_update_table(res.data);
    }

    if (res.name == message_type.search_on_table) {
      update_table(res);
    }

    if (res.name == message_type.add_cortege) {
      if (res.data == "_err") {
        alert("Картеж не может быть добавлен");
      } else {
        alert("Картеж добавлен");
        show_table(res.table_name);
      }
    }

    if (res.name == message_type.delete_cortege) {
      if (res.data == "_err") {
        alert("Картеж не может быть удален");
      } else {
        alert("Картеж удален");
        show_table(res.table_name);
      }
    }

    if (res.name == message_type.update_cortege) {
      if (res.data == "_err") {
        alert("Картеж не может быть обновлен");
      } else {
        alert("Картеж обновлен");
        show_table(res.table_name);
      }
    }

    if (res.name == message_type.get_passenger) {
      document.getElementById("select-table").value =
        "khmilevoi_about_of_passenger";
      update_table(res);
    }

    if (res.name == message_type.show_table) {
      update_table(res);
    }

    if (res.name == message_type.buying_of_ticket) {
      alert("Билет куплен");
    }

    if (res.name == message_type.show_flights) {
      add_flights(res.data);
    }

    if (res.name == message_type.registration_user) {
      alert("Вы успешно зарегистрированны");
    }

    if (res.name == message_type.autorization_admin && res.data.rowCount == 1) {
      alert(`Вы вошли как ${res.data.rows[0].login}`);

      user.login = res.data.rows[0].login;
      user.password = res.data.rows[0].password;
      user.state = state_of_ineterface.li;
      user.type_of_user = type_of_user.admin;
    } else if (res.name == message_type.autorization_admin) {
      alert("Вас нет в системе");
    }

    if (res.name == message_type.autorization_user && res.data.rowCount == 1) {
      alert(
        `Вы вошли как ${res.data.rows[0].firstname} ${
          res.data.rows[0].lastname
        }`
      );

      user.login = `${res.data.rows[0].firstname} ${res.data.rows[0].lastname}`;
      user.firstname = res.data.rows[0].firstname;
      user.lastname = res.data.rows[0].lastname;
      user.phone = res.data.rows[0].phone;
      user.email = res.data.rows[0].email;
      user.pasport_id = res.data.rows[0].pasport_id;
      user.password = `${res.data.rows[0].password}`;
      user.type_of_user = type_of_user.usual;
      user.state = state_of_ineterface.li;
    } else if (res.name == message_type.autorization_user) {
      alert("Вас нет в системе, зарегистрируйтесь");
    }
  }

  if (res.name == message_type.show_orders) {
    show_archiv(res.data);
    alert("Архив обновлен");
  }
};

// Взаимодействие с интерфейсом

function filling_arrays() {
  let response = {
    name: message_type.filling_arrays,
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function show_flights(airport, date, name_class) {
  let response = {
    name: message_type.show_flights,
    data: {
      airport: airport,
      date: date,
      name_class: name_class
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function buying_of_ticket(
  _email,
  _phone,
  _name_of_airport,
  _arrival_date,
  _departure_date,
  _name_of_airline,
  _name_of_class,
  _pasport_id,
  _name_of_age_category,
  _first_name,
  _last_name,
  _gender,
  _date_of_birth
) {
  let response = {
    name: message_type.buying_of_ticket,
    data: {
      order: {
        email: _email,
        phone: _phone,
        name_of_airport: _name_of_airport,
        arrival_date: _arrival_date,
        departure_date: _departure_date,
        name_of_airline: _name_of_airline,
        name_of_class: _name_of_class
      },
      about_of_passenger: {
        pasport_id: _pasport_id,
        name_of_age_category: _name_of_age_category,
        first_name: _first_name,
        last_name: _last_name,
        gender: _gender,
        date_of_birth: _date_of_birth
      }
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function show_orders(phone) {
  let response = {
    name: message_type.show_orders,
    data: {
      phone: phone
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function registration_user(
  firstname,
  lastname,
  password,
  phone,
  email,
  pasport_id
) {
  let response = {
    name: message_type.registration_user,
    data: {
      firstname: firstname,
      lastname: lastname,
      password: password,
      phone: phone,
      email: email,
      pasport_id: pasport_id
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.usual
  };

  ws.send(JSON.stringify(response));
}

function autorization_user(phone, password) {
  let response = {
    name: message_type.autorization_user,
    data: {
      phone: phone,
      password: password
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.usual
  };

  ws.send(JSON.stringify(response));
}

function autorization_admin(_login, _password) {
  let response = {
    name: message_type.autorization_admin,
    data: {
      login: _login,
      password: _password
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function show_table(table_name) {
  let response = {
    name: message_type.show_table,
    data: {
      table_name: table_name
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function get_passenger(number_of_order) {
  let response = {
    name: message_type.get_passenger,
    data: {
      number_of_order: number_of_order,
      table_name: "khmilevoi_about_of_passenger"
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function show_updates() {
  let response = {
    name: message_type.show_updates,
    data: {
      login: user.login
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function search_on_table(table_name, fields, search_tag) {
  let response = {
    name: message_type.search_on_table,
    data: {
      table_name: table_name,
      fields: fields,
      search_tag: search_tag
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

// Изменение таюлиц

function update_cortege(table_name, fields, updates) {
  let response = {
    name: message_type.update_cortege,
    data: {
      table_name: table_name,
      fields: fields,
      updates: updates
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function delete_cortege(table_name, column_name, id) {
  let response = {
    name: message_type.delete_cortege,
    data: {
      table_name: table_name,
      column_name: column_name,
      id: id
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

function add_cortege(table_name, fields, new_data) {
  let response = {
    name: message_type.add_cortege,
    data: {
      table_name: table_name,
      fields: fields,
      new_data: new_data
    },
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.admin
  };

  ws.send(JSON.stringify(response));
}

// Анализ данных

function top_airlines() {
  let response = {
    name: message_type.top_airlines,
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function top_airport() {
  let response = {
    name: message_type.top_airport,
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function flight_congestion() {
  let response = {
    name: message_type.flight_congestion,
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}

function employee_performance() {
  let response = {
    name: message_type.employee_performance,
    login: user.login,
    type_of_user: user.type_of_user,
    use: use.any
  };

  ws.send(JSON.stringify(response));
}
