<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Message</title>
  <meta http-equiv="refresh" content="4; URL=http://index.html">
</head>
<body>
  <?php

  $sendto = "khmilevoi@gmail.com";
  $username = $_POST['name'];
  $usermail = $_POST['email'];
  $usermessage = $_POST['message'];

  $subject = "Новая заявка";
  $headers = "From: " .strip_tags($usermail). "\r\n";
  $headers .= "Reply-To: ". strip_tags($usermail) . "\r\n";
  $headers .= "MIME-Version: 1.0\r\n";
  $headers .= "Content-Type: text/html;charset=utf-8 \r\n";

  $msg  = "<html><body style='font-family:Arial,sans-serif;'>";
  $msg .= "<h2 style='font-weight:bold;border-bottom:1px dotted #ccc;'>Cообщение с сайта портфолио</h2>\r\n";
  $msg .= "<p><strong>От кого:</strong> ".$username."</p>\r\n";
  $msg .= "<p><strong>Почта:</strong> ".$usermail."</p>\r\n";
  $msg .= "<p><strong>Сообщение:</strong> ".$usermessage."</p>\r\n";
  $msg .= "</body></html>";

  if(@mail($sendto, $subject, $msg, $headers)) {
    echo "Спасибо за заявку";
  } else {
    echo "Ошибка. Попробуйте еще";
  }

  ?>

</body>
</html>
