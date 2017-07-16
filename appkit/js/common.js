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
		if ($(this).scrollTop() > $(".header").height()) {
			$("body").addClass("scrolled-header");
		} else {
			$("body").removeClass("scrolled-header");
		}

	});

	//Link

	// about

	$(window).scroll(function() {
		if ($(this).scrollTop() < $(".home").height() + $(".about").height()) {
			$("#home-menu-item-1").addClass("active-link");
		} else {
			$("#home-menu-item-1").removeClass("active-link");
		} if ($(this).scrollTop() < $(".home").height()) {
			$("#home-menu-item-1").removeClass("active-link");
		}

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
		if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height() + $(".pricing").height()) {
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
		} if ($(this).scrollTop() < $(".home").height() + $(".about").height() + $(".testimonials").height() + $(".features").height() + $(".team").height() + $(".pricing").height()) {
			$("#home-menu-item-6").removeClass("active-link");
		}

	});

});
