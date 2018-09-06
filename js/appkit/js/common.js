$(document).ready(function() {

	// Плавный скролл

	$(function() {

		$(".local-link").on('click', 'a', function() {
			event.preventDefault();
			var id 	= $(this).attr('href'),
			top = $(id).offset().top
			$("html,body").animate({scrollTop: top}, 500);
		});

	});

	//Фиксированное меню

	$(window).scroll(function() {
		if ($(this).scrollTop() > $(".header").height()) $("body").addClass("scrolled-header");
		else $("body").removeClass("scrolled-header");
	});

	//Nav-Link

	// about

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() - 50) {
			$("#home-menu-item-1").addClass("active-link");
		} else {
			$("#home-menu-item-1").removeClass("active-link");
		} 
		// if ($(this).scrollTop() < $(".home").height()) {
		// 	$("#home-menu-item-1").removeClass("active-link");
		// }

	});

	// testimonials

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height()) {
			$("#home-menu-item-2").addClass("active-link");
		} else {
			$("#home-menu-item-2").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height()) {
			$("#home-menu-item-2").removeClass("active-link");
		}

	});

	// features

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height()) {
			$("#home-menu-item-3").addClass("active-link");
		} else {
			$("#home-menu-item-3").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height()) {
			$("#home-menu-item-3").removeClass("active-link");
		}

	});

	// team

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height()) {
			$("#home-menu-item-4").addClass("active-link");
		} else {
			$("#home-menu-item-4").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height()) {
			$("#home-menu-item-4").removeClass("active-link");
		}

	});

	// pricing

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height() + $(".pricing").height() / 2) {
			$("#home-menu-item-5").addClass("active-link");
		} else {
			$("#home-menu-item-5").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height()) {
			$("#home-menu-item-5").removeClass("active-link");
		}

	});

	// contact

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height() + $(".pricing").height() + $(".contact").height()) {
			$("#home-menu-item-6").addClass("active-link");
		} else {
			$("#home-menu-item-6").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height() + $(".pricing").height() / 2) {
			$("#home-menu-item-6").removeClass("active-link");
		}

	});

	// Tabbed-area

	// nav-item-1

	$(".nav-item-1").click(function() {
		$(".tabbed-area").addClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-2

	$(".nav-item-2").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").addClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-3

	$(".nav-item-3").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").addClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-4

	$(".nav-item-4").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").addClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-5

	$(".nav-item-5").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").addClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-6

	$(".nav-item-6").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").addClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-7

	$(".nav-item-7").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").addClass("expand-panel-7"),
		$(".tabbed-area").removeClass("expand-panel-8");
	});


	// nav-item-8

	$(".nav-item-8").click(function() {
		$(".tabbed-area").removeClass("expand-panel-1"),
		$(".tabbed-area").removeClass("expand-panel-2"),
		$(".tabbed-area").removeClass("expand-panel-3"),
		$(".tabbed-area").removeClass("expand-panel-4"),
		$(".tabbed-area").removeClass("expand-panel-5"),
		$(".tabbed-area").removeClass("expand-panel-6"),
		$(".tabbed-area").removeClass("expand-panel-7"),
		$(".tabbed-area").addClass("expand-panel-8");
	});

});
