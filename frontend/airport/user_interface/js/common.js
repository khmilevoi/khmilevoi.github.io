function insertAfter(elem, refElem) {
  var parent = refElem.parentNode;
  var next = refElem.nextSibling;
  if (next) {
    return parent.insertBefore(elem, next);
  } else {
    return parent.appendChild(elem);
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

document.getElementById("refresh-icon").addEventListener("click", event => {
  event.preventDefault();

  if (user.state == state_of_ineterface.li) {
    show_orders(user.phone);
  }
});

setInterval(() => {
  let forms = document.getElementsByTagName("form");
  for (let index = 0; index < forms.length; ++index) {
    forms[index].onsubmit = () => {
      return false;
    };
  }

  if (
    user.state == state_of_ineterface.li &&
    user.state_of_interface == state_of_ineterface.nli
  ) {
    document.getElementById("form-login").style.display = "none";

    document.getElementsByClassName("users-name")[0].children[0].innerHTML = `${
      user.login
    }`;
    document.getElementsByClassName("users-name")[0].style.display = "flex";

    show_orders(user.phone);

    user.state_of_interface = state_of_ineterface.li;
  } else if (
    user.state == state_of_ineterface.nli &&
    user.state_of_interface == state_of_ineterface.li
  ) {
    user.reset();
  } else if (
    user.state == state_of_ineterface.nli &&
    user.state_of_interface == state_of_ineterface.nli
  ) {
    document.getElementById("form-login").style.display = "flex";

    document.getElementsByClassName("users-name")[0].children[0].innerHTML = ``;
    document.getElementsByClassName("users-name")[0].style.display = "none";
  }
}, 500);

document.getElementById("sign-out").addEventListener("click", event => {
  event.preventDefault();

  user.reset();

  document.getElementsByClassName("archiv")[1].innerHTML = ` <div class="nope">
              Необходимо авторизоваться для просмотра архива
            </div>`;

  alert("Вы вышли");
});

window.onload = () => {
  check_active_div();
  filling_arrays();
};

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

function filling_select() {
  let arr;

  let airports = document.getElementById("search-airport");

  if (airports.childElementCount == 0) {
    arr = arrays[0];
    for (let airport = 0; airport < arr.length; ++airport) {
      let option = document.createElement("option");
      option.value = arr[airport];

      let text = document.createTextNode(
        arr[airport][0].toUpperCase() + arr[airport].slice(1).toLowerCase()
      );

      option.appendChild(text);

      airports.appendChild(option);
    }
  }

  let categories = document.getElementsByClassName("name-of-age-category");

  arr = arrays[4];

  for (let select = 0; select < categories.length; ++select) {
    if (categories[select].childElementCount == 0) {
      for (let category = 0; category < arr.length; ++category) {
        let option = document.createElement("option");
        option.value = arr[category];

        let text = document.createTextNode(
          arr[category][0].toUpperCase() + arr[category].slice(1).toLowerCase()
        );

        option.appendChild(text);

        categories[select].appendChild(option);
      }
    }
  }
}

document.getElementById("search-flights").addEventListener("click", event => {
  event.preventDefault();

  let airport = document.getElementById("search-airport").value;
  let date = document.getElementById("search-date").value;
  let name_class = document.getElementById("search-class-first").checked
    ? "first"
    : "econom";

  show_flights(airport, date, name_class);
});

function add_flights(data) {
  let flight = [];

  for (let index = 0; index < data.rowCount; ++index) {
    let cash = [];
    for (let index2 = 0; index2 < data.fields.length; ++index2) {
      cash.push(data.rows[index][data.fields[index2].name]);
    }
    flight.push(cash);
  }

  let parent = document.getElementsByClassName("flights")[0];
  parent.innerHTML = "";

  for (let index = 0; index < flight.length; ++index) {
    let div = document.createElement("div");
    div.className += "flight";
    div.innerHTML = `
      <div class="information">
        <div class="airline">${flight[index][0]}</div>
        <div class="arrival-date">
        ${flight[index][1]
          .replace("T", " ")
          .replace("Z", "")
          .replace(".000", "")}
        </div>
        <div class="departure-date">
        ${flight[index][2]
          .replace("T", " ")
          .replace("Z", "")
          .replace(".000", "")}
        </div>
      </div>
      <div class="buying">
        <div class="rate">${flight[index][3]} грн.</div>
        <button class="select-flight">Выбрать</button>
      </div>
      <div class="amount-of-seates">${Number(flight[index][5]) -
        Number(flight[index][4])} мест</div>
    `;

    parent.appendChild(div);
  }

  listening_button();
}

function listening_button() {
  let btn_flight = document.getElementsByClassName("select-flight");

  for (let index = 0; index < btn_flight.length; ++index) {
    btn_flight[index].addEventListener("click", event => {
      event.preventDefault();

      if (
        btn_flight[index].parentElement.parentElement.nextElementSibling ==
          null ||
        btn_flight[index].parentElement.parentElement.nextElementSibling
          .className != "buying-information"
      ) {
        let info = document.createElement("div");
        info.className += "buying-information";
        info.innerHTML = `
      <h2>Данные пассажира</h2>
      <form id="form-buying">
        <input
          type="text"
          name="reg-lastname"
          class="reg-lastname"
          placeholder="Введите фамилию"
          value = "${user.lastname}"
          required
        />
        <input
          type="text"
          name="reg-firstname"
          class="reg-firstname"
          placeholder="Введите имя"
          value = "${user.firstname}"
          required
        />
        <input
          type="phone"
          name="reg-phone"
          class="reg-phone"
          placeholder="Введите телефон"
          value = "${user.phone}"
          required
        />
        <input
          type="email"
          name="reg-email"
          class="reg-email"
          placeholder="Введите email"
          value = "${user.email}"
          required
        />
        <div class="radio radio-gender">
          <input
            type="radio"
            name="gender"
            id="buying-gender-male-${index}"
            value="male"
            checked
          />
          <label for="buying-gender-male-${index}">М</label>
          <input
            type="radio"
            name="gender"
            id="buying-gender-female-${index}"
            value="female"
          />
          <label for="buying-gender-female-${index}">Ж</label>
        </div>
        <input
          type="date"
          name="buying-date"
          class="buying-date"
          placeholder="Введите дату рождения"
          value="2000-01-18"
          required
        />
        <select class="name-of-age-category">
        </select>
        <input
          type="text"
          name="pasport-id"
          class="buying-pasport-id"
          placeholder="Введите id паспорта"
          value = "${user.pasport_id}"
          required
        />
        <button class="btn-buying">Купить</button>
      </form>
    `;

        insertAfter(info, btn_flight[index].parentElement.parentElement);
      }

      filling_select();

      listening_buying();
    });
  }
}

function listening_buying() {
  let buttons = document.getElementsByClassName("btn-buying");

  for (let index = 0; index < buttons.length; ++index) {
    let buy = event => {
      event.preventDefault();

      let flight_div = document.getElementsByClassName("flight");

      for (let flight = 0; flight < flight_div.length; ++flight) {
        if (
          flight_div[flight].nextElementSibling ==
          buttons[index].parentElement.parentElement
        ) {
          let info = buttons[index].parentElement.parentElement;

          let lastname = info.children[1].children[0].value;
          let firstname = info.children[1].children[1].value;
          let phone = info.children[1].children[2].value;
          let email = info.children[1].children[3].value;
          let gender = info.children[1].children[4].children[0].checked
            ? "male"
            : "female";
          let date_of_birth = info.children[1].children[5].value;
          let category = info.children[1].children[6].value;
          let pasport_id = info.children[1].children[7].value;

          let airline = flight_div[flight].children[0].children[0].textContent;
          let date_arrive =
            flight_div[flight].children[0].children[1].textContent;
          let date_departure =
            flight_div[flight].children[0].children[2].textContent;
          let amount_seates = flight_div[flight].children[2].textContent.split(
            " "
          )[0];

          let airport = document.getElementById("search-airport").value;
          let class_n = document.getElementById("search-class-first").checked
            ? "first"
            : "econom";

          if (lastname == "" || firstname == "" || phone == "" || email == "") {
            alert("Заполните все поля");
            return;
          }

          if (amount_seates <= 0) {
            alert("Мест нет");
            return;
          }

          buying_of_ticket(
            email,
            phone,
            airport,
            date_arrive,
            date_departure,
            airline,
            class_n,
            pasport_id,
            category,
            firstname,
            lastname,
            gender,
            date_of_birth
          );

          let date = document.getElementById("search-date").value;

          show_flights(airport, date, class_n);
        }
      }
    };

    if (buttons[index].className.indexOf("listening") < 0) {
      buttons[index].addEventListener("click", buy);
      buttons[index].className += " listening";
    }
  }
}

document.getElementById("btn-registration").addEventListener("click", event => {
  event.preventDefault();

  let pop_up = document.getElementsByClassName("pop-up-registration")[0];

  if (pop_up.className.indexOf("show") < 0) {
    pop_up.className += " show";
  }
});

document.getElementById("close-btn").addEventListener("click", event => {
  event.preventDefault();

  let pop_up = document.getElementsByClassName("pop-up-registration")[0];

  if (pop_up.className.indexOf("show") >= 0) {
    pop_up.className = pop_up.className.replace(" show", "");
  }
});

document.getElementById("btn-reg").addEventListener("click", event => {
  event.preventDefault();

  let firstname = document.getElementById("reg-firstname").value;
  let lastname = document.getElementById("reg-lastname").value;
  let phone = document.getElementById("reg-phone").value;
  let email = document.getElementById("reg-email").value;
  let pasport_id = document.getElementById("reg-pasport-id").value;
  let password = document.getElementById("reg-password").value;

  if (
    firstname == "" ||
    lastname == "" ||
    phone == "" ||
    password == "" ||
    email == "" ||
    pasport_id == ""
  ) {
    alert("Заполните все поля");
    return;
  }

  registration_user(firstname, lastname, password, phone, email, pasport_id);
});

function show_archiv(data) {
  document.getElementsByClassName("archiv")[1].innerHTML = "";

  for (let index = 0; index < data.rowCount; ++index) {
    let ticket = document.createElement("div");
    ticket.className += "ticket";

    ticket.innerHTML = `
    <div class="cost accent">${data.rows[index].rate} грн.</div>
      <div class="flight-info">
        <div class="airline">${data.rows[index].name_of_airline}</div>
        <div class="destination">
          <div class="airport accent">${data.rows[index].name_of_airport}</div>
          <div class="country">${data.rows[index].name_of_country}</div>
        </div>
        <div class="time">
          <div class="arrival-date">${data.rows[index].arrival_date
            .replace("T", " ")
            .replace("Z", "")
            .replace(".000", "")}</div>
          <div class="deporture-date">${data.rows[index].departure_date
            .replace("T", " ")
            .replace("Z", "")
            .replace(".000", "")}</div>
        </div>
        <div class="class">${data.rows[index].name_of_class}</div>
      </div>
      <div class="passenger-info">
        <div class="name accent">${data.rows[index].name}</div>
        <div class="phone">${data.rows[index].phone}</div>
        <div class="email">${data.rows[index].e_mail}</div>
        <div class="gender">${data.rows[index].gender}</div>
        <div class="date-of-birth">${data.rows[index].date_of_birth
          .replace("T", " ")
          .replace("Z", "")
          .replace(".000", "")}</div>
        <div class="categry">${data.rows[index].name_of_age_category}</div>
      </div>
    `;

    document.getElementsByClassName("archiv")[1].appendChild(ticket);
  }
}

document.getElementById("btn-login").addEventListener("click", event => {
  event.preventDefault();

  let phone = document.getElementById("phone-login").value;
  let password = document.getElementById("password-login").value;

  if (phone == "" || phone == "") {
    alert("Заполните все поля");
    return;
  }

  autorization_user(phone, password);
});
