$(document).ready(function() {

	// // Плавный скролл по ссылке
	//
	// $(".local-link").on('click', 'a', function() {
	// 	event.preventDefault();
	// 	var id 	= $(this).attr('href'),
	// 	top = $(id).offset().top
	// 	$("html,body").animate({scrollTop: top}, 500);
	// });

	// Меню (mobile)

	$(".button-menu").click(function () {
		$("body").toggleClass("active-button-menu");
	})

	// Ссылки меню

	$(".main-menu--list-item-1").click(function () {
		$("body").addClass("active-link-1"),
		$("body").removeClass("active-link-2"),
		$("body").removeClass("active-link-3"),
		$("body").removeClass("active-link-4"),
		$("body").removeClass("active-button-menu");
	});

	$(".main-menu--list-item-2").click(function () {
		$("body").addClass("active-link-2"),
		$("body").removeClass("active-link-1"),
		$("body").removeClass("active-link-3"),
		$("body").removeClass("active-link-4"),
		$("body").removeClass("active-button-menu");
	});

	$(".main-menu--list-item-3").click(function () {
		$("body").addClass("active-link-3"),
		$("body").removeClass("active-link-1"),
		$("body").removeClass("active-link-2"),
		$("body").removeClass("active-link-4"),
		$("body").removeClass("active-button-menu");
	});

	$(".main-menu--list-item-4").click(function () {
		$("body").addClass("active-link-4"),
		$("body").removeClass("active-link-1"),
		$("body").removeClass("active-link-2"),
		$("body").removeClass("active-link-3"),
		$("body").removeClass("active-button-menu");
	});

	// Прелоадер

	$(window).on("load", function () {
	 $preloader = $(".page-preloader"),
		 $loader = $preloader.find(".loader");
	 $loader.delay(3000).fadeOut("slow");
	 $preloader.delay(3000).fadeOut("slow");
 });

});
