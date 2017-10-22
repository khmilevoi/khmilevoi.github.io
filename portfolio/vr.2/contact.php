<?php

$name = $_POST['name'];
$email = $_POST['email'];
$message = $_POST['message'];
$token = "460722809:AAGqFU3rcFyKYbSkgjhcBkEbSBzZFW4xJsw";
$chat_id = "-192893038";

$arr = array(
  'Имя пользователя: ' = $name,
  'Email Пользователя: ' = $email,
  'Сообщение пользователя' = $message
);

foreach ($arr as $key => $value) {
  $text .= "<b>".$key."</b>".$value."%0A"
};

$sendToTelegram = fopen("https://api.telegram.org/bot{$token}/sendMessage?chat_id={$chat_id}&parse_mode=html&text={$txt}", "r");

if ($sendToTelegram) {
  echo "Спасибо за заявку!";
} else {
  echo "Error";
}
?>
