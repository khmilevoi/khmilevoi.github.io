$(document).ready(function() {

  // Прелоадер

  $(window).on("load", function () {
    var $preloader = $(".page-preloader"),
    $loader = $(".loader");
    $loader.fadeOut();
    $preloader.delay(350).fadeOut("slow");
  });

  // Плавный скролл по ссылке

  $(".local-link").on("click", "a", function() {
    event.preventDefault();
    var id 	= $(this).attr("href"),
    length = $(id).offset().top;
    $("html,body").animate({scrollTop: length}, 400);
  });

  // Пользовательские функции

  // Фиксированное меню

  $(window).scroll(function() {
    if ($(this).scrollTop() > $(".home").height() - 80) {
      $(".header").addClass("header-scrolled");
    } else {
      $(".header").removeClass("header-scrolled");
    }
  });

  // Скролл вверх
  $(".scroll-up").hide();
  $(window).scroll(function() {
    if ($(this).scrollTop() > $(".home").height() - 10) {
      $(".scroll-up").fadeIn("1000");
    } else {
      $(".scroll-up").fadeOut("1000");
    }
  });

  // Подсветка пунктов меню

  var menu_selector = ".menu-itm-wrapper";

  function onScroll(){
    var scroll_top = $(document).scrollTop() + 80;
    $(menu_selector + " a").each(function(){
      var hash = $(this).attr("href");
      var target = $(hash);
      if (target.position().top <= scroll_top && target.position().top + target.outerHeight() > scroll_top) {
        $(menu_selector + " a.active").removeClass("active");
        $(this).addClass("active");
      } else {
        $(this).removeClass("active");
      }
    });
  }

  $(document).ready(function () {

    $(document).on("scroll", onScroll);

    $("a[href^=#]").click(function(e){
      e.preventDefault();

      $(document).off("scroll");
      $(menu_selector + " a.active").removeClass("active");
      $(this).addClass("active");
      var hash = $(this).attr("href");
      var target = $(hash);

      $("html, body").animate({
        scrollTop: target.offset().top
      }, 500, function(){
        window.location.hash = hash;
        $(document).on("scroll", onScroll);
      });

    });

  });

  // Кнопка Меню

  $(".btn-wrapper").click(function () {
    $(".main-menu-wrapper").toggleClass("activeMenuBtn");
  });

  $(".mobile .menu-itm a").click(function () {
    $(".main-menu-wrapper").removeClass("activeMenuBtn")
  });

  // Шкалы умений

  $(window).scroll(function () {
    if ($(this).scrollTop() > $(".skills").offset().top - 100) {
      $(".scale-wrapper").each(function () {
        $(this).find(".skill-scale").animate({
          width: $(this).data("width")
        }, 2000)
      });
    } else {
      $(".skill-scale").attr("style", "width:100% !important");
    }
  });

  // Конец

});
