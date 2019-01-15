const Pool = require("pg").Pool;
const web_socket = require("ws");
const express = require("express");
const path = require("path");

const airport = {
  host: "localhost",
  user: "postgres",
  password: "53574268sat",
  database: "airport"
};

const employees = {
  host: "localhost",
  user: "postgres",
  password: "53574268sat",
  database: "airports_employees"
};

const users = {
  host: "localhost",
  user: "postgres",
  password: "53574268sat",
  database: "airport_users"
};

const airport_pool = new Pool(airport);
const employees_pool = new Pool(employees);
const users_pool = new Pool(users);

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

const type_of_user = {
  admin: "admin",
  usual: "usual"
};

const use = {
  admin: "admin",
  usual: "usual",
  any: "any"
};

const PORT = process.env.PORT || 3000;
const INDEX = path.join(__dirname, "../user_interface/index.html");

const server = express()
  .use((req, res) => res.sendFile(INDEX))
  .listen(PORT, () => console.log(`Listening on ${PORT}`));

const wss = new web_socket.Server({ server });

wss.on("connection", (ws, res) => {
  console.log("Client connected");
  ws.on("close", () => console.log("Client disconnected"));

  ws.on("message", message => {
    wss.clients.forEach(async client => {
      if (client.readyState == web_socket.OPEN) {
        if (message != "undefined") {
          message = JSON.parse(message);
          console.log(message.name);
          let data = "";

          if (JSON.stringify(message_type).indexOf(message.name) > 0) {
            data = await eval(message.name)(message);
          } else {
            console.error("ERROR > undefined command");
          }

          if (
            message.use == use.admin &&
            message.name != message_type.autorization_admin &&
            message.name != message_type.get_passenger &&
            message.name != message_type.show_table &&
            message.name != message_type.show_updates &&
            data.indexOf("_err") < 0
          ) {
            registration_of_updates(
              {
                login: message.login,
                type_of_user: message.type_of_user
              },
              message.name,
              JSON.stringify(message.data)
            );
          }

          console.log(`\tlog in ${message.login}(${message.type_of_user})`);
          client.send(data);
        }
      }
    });
  });
});

// Запросы

async function registration_of_updates(user, type_of_update, new_data) {
  if (user.type_of_user == type_of_user.admin) {
    let data = await employees_pool.query(
      `
        insert into updates(id_of_employee, text_of_update, date)
        values(
            (select id from employees e where (e.first_name || '_' || e.last_name) = '${
              user.login
            }'),
            '${type_of_update} ${new_data}', 'now'::timestamp
        );

        `
    );
  }
}

// Авторизация

async function autorization_admin(response) {
  let data = await employees_pool.query(
    `
    select first_name || '_' || last_name as login, password as password
    from employees 
    where   first_name || '_' || last_name = '${response.data.login}'
            and password = '${response.data.password}';
    `
  );

  let request = {
    data: data,

    name: message_type.autorization_admin
  };

  return JSON.stringify(request);
}

async function registration_user(response) {
  let data = await users_pool.query(
    `
    insert into users(firstname, lastname, password, phone, email, pasport_id)
    values('${response.data.firstname}', '${response.data.lastname}', '${
      response.data.password
    }', '${response.data.phone}', '${response.data.email}', ${
      response.data.pasport_id
    });
    `
  );

  let request = {
    data: data,
    name: message_type.registration_user
  };

  return JSON.stringify(request);
}

async function autorization_user(response) {
  let data = await users_pool.query(
    `
    select *
    from users 
    where   phone = '${response.data.phone}'
            and password = '${response.data.password}';
    `
  );

  let request = {
    data: data,
    name: message_type.autorization_user
  };

  return JSON.stringify(request);
}

// Изменнение таблиц

async function buying_of_ticket(response) {
  let data = await airport_pool.query(
    `
     insert into khmilevoi_order (
        e_mail, 
        phone,
        number_of_flight,
        id_of_class
    )
    values (
        upper('${response.data.order.email.toUpperCase()}'),
        ${response.data.order.phone},
        (select number_of_flight
        from khmilevoi_about_of_flight , khmilevoi_airports, khmilevoi_airlines
        where 
		upper('${response.data.order.name_of_airport.toUpperCase()}') = khmilevoi_airports.name_of_airport
        and khmilevoi_about_of_flight.id_of_airport = khmilevoi_airports.id_of_airport
		and arrival_date = '${response.data.order.arrival_date}'
		and departure_date = '${response.data.order.departure_date}'
    and khmilevoi_about_of_flight.id_of_airline = khmilevoi_airlines.id_of_airline
    and upper('${response.data.order.name_of_airline.toUpperCase()}') = khmilevoi_airlines.name_of_airline),
        (select id_of_class
        from khmilevoi_classes
        where khmilevoi_classes.name_of_class = upper('${response.data.order.name_of_class.toUpperCase()}'))
    );

    insert into khmilevoi_about_of_passenger (
        pasport_id,
        number_of_order,
        id_of_age_category,
        first_name,
        last_name,
        gender,
        date_of_birth
    )
    values(
        ${response.data.about_of_passenger.pasport_id},
        (select max(number_of_order) from khmilevoi_order),
        (select id_of_age_category
        from khmilevoi_age_categories
        where name_of_age_category = upper('${response.data.about_of_passenger.name_of_age_category.toUpperCase()}')),
        '${response.data.about_of_passenger.first_name.toUpperCase()}',
        '${response.data.about_of_passenger.last_name.toUpperCase()}',
        '${response.data.about_of_passenger.gender.toUpperCase()}',
        date('${response.data.about_of_passenger.date_of_birth}')
    );
    `
  );

  let request = {
    data: data,
    name: message_type.buying_of_ticket
  };

  return JSON.stringify(request);
}

async function filling_arrays() {
  let data = await airport_pool.query(
    `
    select distinct name_of_airport
    from khmilevoi_airports, khmilevoi_about_of_flight
    where khmilevoi_airports.id_of_airport = khmilevoi_about_of_flight.id_of_airport;
    
    select distinct name_of_country
    from khmilevoi_countries;

    select distinct name_of_airline
    from khmilevoi_airlines, khmilevoi_about_of_flight
    where khmilevoi_airlines.id_of_airline = khmilevoi_about_of_flight.id_of_airline;	

    select distinct name_of_class
    from khmilevoi_classes;	

    select distinct name_of_age_category
    from khmilevoi_age_categories;	

    select table_name
    from information_schema.tables where table_schema='public'
    `
  );

  let request = {
    data: data,
    name: message_type.filling_arrays
  };

  return JSON.stringify(request);
}

async function show_orders(response) {
  let data = await airport_pool.query(
    `
    select rate, name_of_airline, name_of_airport, name_of_country, arrival_date, departure_date, name_of_class, last_name || ' ' || first_name as name, gender, phone, e_mail, date_of_birth, name_of_age_category
    from khmilevoi_rate, khmilevoi_airlines, khmilevoi_airports, khmilevoi_countries, khmilevoi_about_of_flight, khmilevoi_classes, khmilevoi_about_of_passenger, khmilevoi_order, khmilevoi_age_categories
    where
    khmilevoi_order.number_of_flight = khmilevoi_about_of_flight.number_of_flight
    and khmilevoi_about_of_flight.id_of_airline = khmilevoi_airlines.id_of_airline
    and khmilevoi_about_of_flight.id_of_airport = khmilevoi_airports.id_of_airport
    and khmilevoi_airports.id_of_country = khmilevoi_countries.id_of_country
    and khmilevoi_classes.id_of_class = khmilevoi_order.id_of_class
    and khmilevoi_about_of_passenger.number_of_order = khmilevoi_order.number_of_order
    and khmilevoi_about_of_passenger.id_of_age_category = khmilevoi_age_categories.id_of_age_category
    and khmilevoi_rate.id_of_class = khmilevoi_order.id_of_class
    and khmilevoi_order.phone = '${response.data.phone}'
    order by khmilevoi_order.number_of_order desc
    `
  );

  let request = {
    data: data,
    name: message_type.show_orders
  };

  return JSON.stringify(request);
}

async function show_flights(response) {
  let data = await airport_pool.query(
    `
    select name_of_airline, to_char(arrival_date, 'yyyy-mm-dd hh24:mi:ss') as arrival, to_char(departure_date, 'yyyy-mm-dd hh24:mi:ss') as departure, rate, count(khmilevoi_order.number_of_flight), number_of_seates
    from khmilevoi_rate, khmilevoi_about_of_flight
    left join  khmilevoi_order on khmilevoi_order.number_of_flight = khmilevoi_about_of_flight.number_of_flight, khmilevoi_airlines
    where 
    khmilevoi_about_of_flight.id_of_airline = khmilevoi_airlines.id_of_airline
    and khmilevoi_about_of_flight.id_of_airport = (select id_of_airport from khmilevoi_airports where name_of_airport = upper('${
      response.data.airport
    }'))
    and khmilevoi_about_of_flight.arrival_date >= '${response.data.date}'
    and khmilevoi_rate.id_of_class = (select id_of_class from khmilevoi_classes where name_of_class = upper('${
      response.data.name_class
    }'))			
    group by khmilevoi_about_of_flight.number_of_flight, name_of_airline, arrival_date, departure_date, rate
    `
  );

  let request = {
    data: data,
    name: message_type.show_flights
  };

  return JSON.stringify(request);
}

async function show_table(response) {
  let data = await airport_pool.query(
    `
    select * from ${response.data.table_name} order by 1 desc;
    `
  );

  let request = {
    data: data,
    name: message_type.show_table,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

async function get_passenger(response) {
  let data = await airport_pool.query(
    `
    select * from khmilevoi_about_of_passenger where number_of_order = ${
      response.data.number_of_order
    }
    `
  );

  let request = {
    data: data,
    name: message_type.get_passenger,
    table_name: "khmilevoi_about_of_passenger"
  };

  return JSON.stringify(request);
}

async function update_cortege(response) {
  console.log("\t", response.data.table_name);

  var query = "";

  if (response.data.fields.length > 2) {
    query += "(";

    for (let index = 1; index < response.data.fields.length; ++index) {
      query += response.data.fields[index];

      if (index < response.data.fields.length - 1) {
        query += ", ";
      }
    }

    query += ")";

    query += " = ";

    query += "(";

    for (let index = 1; index < response.data.updates.length; ++index) {
      query += "'" + response.data.updates[index].toUpperCase() + "'";

      if (index < response.data.updates.length - 1) {
        query += ", ";
      }
    }

    query += ")";
  } else {
    query += response.data.fields[1];
    query += " = ";
    query += "'" + response.data.updates[1].toUpperCase() + "'";
  }

  var data = await airport_pool
    .query(
      `
      update ${response.data.table_name} 
      set ${query}
      where ${response.data.fields[0]} = ${Number(response.data.updates[0])}
      `
    )
    .catch(reason => {
      console.log(reason);

      return "_err";
    });

  let request = {
    data: data,
    name: message_type.update_cortege,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

async function delete_cortege(response) {
  console.log("\t", response.data.table_name);

  let data = await airport_pool
    .query(
      `
    delete from ${response.data.table_name}
    where ${response.data.column_name} = ${response.data.id}
    `
    )
    .catch(reason => {
      console.log(reason);

      return "_err";
    });

  let request = {
    data: data,
    name: message_type.delete_cortege,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

async function add_cortege(response) {
  console.log("\t", response.data.table_name);

  let source = "(";

  for (let index = 0; index < response.data.fields.length; ++index) {
    source += response.data.fields[index];

    if (index < response.data.fields.length - 1) {
      source += ",";
    }
  }
  source += ")";

  let query = "values(";

  for (let index = 0; index < response.data.new_data.length; ++index) {
    if (index < response.data.new_data.length - 1) {
      query += "'" + response.data.new_data[index].toUpperCase() + "'" + ", ";
    } else {
      query += "'" + response.data.new_data[index].toUpperCase() + "'";
    }
  }

  query += ")";

  let data = await airport_pool
    .query(
      `
    insert into ${response.data.table_name}${source}
    ${query};
    `
    )
    .catch(reason => {
      console.log(reason);

      return "_err";
    });

  let request = {
    data: data,
    name: message_type.add_cortege,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

async function show_updates(response) {
  let data = await employees_pool.query(
    `
    select number_of_update, text_of_update, date from updates, employees
    where id = id_of_employee and first_name || '_' || last_name = '${
      response.data.login
    }' order by number_of_update desc
    `
  );

  let request = {
    data: data,
    name: message_type.show_updates,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

async function search_on_table(response) {
  var query = "";

  for (let index = 0; index < response.data.fields.length; ++index) {
    query += `upper(${
      response.data.fields[index]
    }::text) = '${response.data.search_tag.toUpperCase()}'`;

    if (index < response.data.fields.length - 1) {
      query += " or ";
    }
  }

  let data = await airport_pool.query(`
  select * from ${response.data.table_name}
  where ${query}
  `);

  let request = {
    data: data,
    name: message_type.search_on_table,
    table_name: response.data.table_name
  };

  return JSON.stringify(request);
}

// Аналих данных

async function top_airlines(response) {
  let data = await airport_pool.query(
    `
    select name_of_airline as name, count(name_of_airline) as count
    from khmilevoi_airlines as a, khmilevoi_about_of_flight as f, khmilevoi_order as o
    where a.id_of_airline = f.id_of_airline and f.number_of_flight = o.number_of_flight
    group by name_of_airline
    order by count desc
    `
  );

  let request = {
    data: data,
    name: message_type.top_airlines
  };

  return JSON.stringify(request);
}

async function top_airport(response) {
  let data = await airport_pool.query(
    `
    select name_of_airport as name, count(name_of_airport) as count
    from khmilevoi_airports as a, khmilevoi_about_of_flight as f, khmilevoi_order as o
    where a.id_of_airport = f.id_of_airport and f.number_of_flight = o.number_of_flight
    group by name_of_airport
    order by count desc
    `
  );

  let request = {
    data: data,
    name: message_type.top_airport
  };

  return JSON.stringify(request);
}

async function flight_congestion(response) {
  let data = await airport_pool.query(
    `
    select khmilevoi_about_of_flight.number_of_flight || '_' || khmilevoi_airlines.name_of_airline || '_' || khmilevoi_airports.name_of_airport || '_' || arrival_date::date || '_' || arrival_date::time as name, count(khmilevoi_order.number_of_flight) as count, number_of_seates
    from khmilevoi_airlines, khmilevoi_airports,
    khmilevoi_about_of_flight left join khmilevoi_order on khmilevoi_about_of_flight.number_of_flight = khmilevoi_order.number_of_flight
    where khmilevoi_airlines.id_of_airline = khmilevoi_about_of_flight.id_of_airline
    and khmilevoi_airports.id_of_airport = khmilevoi_about_of_flight.id_of_airport
    group by name, number_of_seates
    order by (count(khmilevoi_order.number_of_flight) * 100) / number_of_seates desc
    `
  );

  let request = {
    data: data,
    name: message_type.flight_congestion
  };

  return JSON.stringify(request);
}

async function employee_performance(response) {
  let data = await employees_pool.query(`
  select first_name || ' ' || last_name as name, count(id_of_employee) as count
  from employees, updates
  where id_of_employee = id
  group by name
  order by count desc
  `);

  let request = {
    data: data,
    name: message_type.employee_performance
  };

  return JSON.stringify(request);
}
