// Base

var information_wrapper = document.getElementsByClassName("main-block");

for (let index = 0; index < information_wrapper.length; ++index) {

    if (
        information_wrapper[index].className.indexOf("cv") == -1 &&
        information_wrapper[index].className.indexOf("contact-form") == -1 &&
        information_wrapper[index].className.indexOf("slider-wrapper") == -1
    ) {

        information_wrapper[index].addEventListener("click", () => {

            information_wrapper[index].classList.toggle("active");
        })
    }

}

delete information_wrapper;

var tables_rows = document.getElementsByTagName("tr");
var color_of_tables_rows = [];

for (let index = 0; index < tables_rows.length; ++index) {

    color_of_tables_rows.push(getComputedStyle(tables_rows[index]).backgroundColor);
}

for (let index = 0; index < tables_rows.length; ++index) {

    tables_rows[index].addEventListener("mouseover", () => {

        tables_rows[index].style.backgroundColor = "#d4d4d4";
    });
    tables_rows[index].addEventListener("mouseout", () => {

        tables_rows[index].style.backgroundColor = color_of_tables_rows[index];
    });
}

delete tables_rows;
delete color_of_tables_rows;

// Middle

var information_wrapper = document.getElementsByClassName("main-block");

document.onkeydown = function (event) {

    for (let index = 0; index < information_wrapper.length; ++index) {

        if (event.keyCode == String(index).charCodeAt(0)) {

            scrollBy(0, (information_wrapper[index].offsetTop - window.pageYOffset));
        }
    }
}

delete information_wrapper;


function validation_of_form() {

    var vp = validation_of_phone();
    var vm = validation_of_mail();

    if (!(vp && vm)) {
        setTimeout(validation_of_form, 1000);
    }

    return vp && vm;
}

function validation_of_phone() {

    var regular_expression = /^[+]{1}[0-9]{2}[(]{1}[0-9]{3}[)]{1}[0-9]{7}$/;
    var validation = regular_expression.test(document.getElementsByClassName("contact-phone")[0].value);

    if (validation) {

        document.getElementsByClassName("contact-phone")[0].style.borderColor = "#00AC48";
        document.getElementsByClassName("message-phone")[0].innerHTML = "";
    } else {

        document.getElementsByClassName("contact-phone")[0].style.borderColor = "tomato";
        document.getElementsByClassName("contact-phone")[0].style.marginBottom = "5px";
        document.getElementsByClassName("message-phone")[0].innerHTML = "Неверный ввод. Формат ввода: +99(999)9999999";
    }

    return validation;
}

function validation_of_mail() {

    var regular_expression = /^(?!.*@.*@.*$)(?!.*@.*\-\-.*\..*$)(?!.*@.*\-\..*$)(?!.*@.*\-$)(.+@.+\..+)$/;
    var validation = regular_expression.test(document.getElementsByClassName("contact-mail")[0].value);

    if (validation) {

        document.getElementsByClassName("contact-mail")[0].style.borderColor = "#00AC48";
        document.getElementsByClassName("message-mail")[0].innerHTML = "";
    } else {

        document.getElementsByClassName("contact-mail")[0].style.borderColor = "tomato";
        document.getElementsByClassName("contact-mail")[0].style.marginBottom = "5px";
        document.getElementsByClassName("message-mail")[0].innerHTML = "Неверный ввод. Формат ввода: yourEmail@mail.com";
    }

    return validation;
}

// Hard

var current_slide = 1;
show_slides(current_slide);

document.getElementsByClassName("prev")[0].addEventListener("click", () => {

    show_slides(current_slide - 1);
});
document.getElementsByClassName("next")[0].addEventListener("click", () => {

    show_slides(current_slide + 1);
});

var slider_dots = document.getElementsByClassName("slider-dots_item");

for (let index = 0; index < slider_dots.length; ++index) {

    slider_dots[index].addEventListener("click", () => {
        show_slides(index + 1);
    });
}

setInterval(() => {
    show_slides(current_slide + 1);
}, 5000);

function show_slides(number_of_slide) {

    current_slide = number_of_slide;
    var slides = document.getElementsByClassName("item");
    var dots = document.getElementsByClassName("slider-dots_item");

    if (number_of_slide > slides.length) {
        current_slide = 1
    }

    if (number_of_slide < 1) {
        current_slide = slides.length
    }

    for (let index = 0; index < slides.length; ++index) {
        slides[index].style.display = "none";
        dots[index].className = dots[index].className.replace(" active", "");
    }

    slides[current_slide - 1].style.display = "block";
    dots[current_slide - 1].className += " active";
}

delete current_slide;

var interval_id;

var opacity = 0;
var shift = 0.01;

window.onload = () => {

    interval_id = setInterval(() => {

        if (opacity >= 1) {
            clearInterval(interval_id);
        }
        opacity += shift;
        document.body.style.opacity = opacity;
    }, 20);
}

delete interval_id;
delete opacity;
delete shift;

var images = document.getElementsByTagName("img");

document.getElementsByClassName("close-button")[0].addEventListener("click", () => {
    document.getElementsByClassName("pop-up-wrapper")[0].style.display = "none";
    document.body.style.overflow = "visible";
});

for (let index = 0; index < images.length; ++index) {

    images[index].addEventListener("click", () => {

        if (images[index].className.indexOf("pop-up") == -1) {

            document.getElementsByClassName("pop-up-wrapper")[0].style.display = "flex";
            document.body.style.overflow = "hidden";

            document.getElementsByClassName("pop-up-img")[0].setAttribute("src", images[index].getAttribute("src"));
        }
    });
}