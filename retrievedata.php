<?php
//connecting database
$dbhost = '192.168.0.32';
$dbuser = 'avuser';
$dbpass = 'srmri@12345';
$conn = mysql_connect($dbhost, $dbuser, $dbpass);
if(! $conn )
{
  die('Could not connect: ' . mysql_error());
}
$db = mysql_select_db('db_atihav');

//collect data from QandQ table;
//$sql = 'SELECT id, user_id, AFactor, datetime FROM QandQ';
$sql = 'SELECT avg(AFactor) AS AvgAtt FROM QandQ WHERE user_id=3';

$query = mysql_query($sql);
if(! $query )
{
  die('Could not get data: ' . mysql_error());
}
while($info = mysql_fetch_array($query))
{
	print "<b>USER ID: 3</b> ";
        print "<b>Average Attendance FACTOR:</b>".$info['AvgAtt'] . " ";
/*     
	print "<b>ID:</b>".$info['id'] . " ";
	print "<b>USER ID:</b>".$info['user_id'] . " ";
	print "<b>AFACTOR:</b>".$info['AFactor'] . " ";
	print "<b>DATE TIME:</b>".$info['datetime'] . " <br>";
*/
if(AvgAtt<0.40)
{
      echo '<script> alert("Late");</script>';
}
else
{
 echo '<script> alert("ok");</script>';
}


} 


//echo "Fetched data successfully\n";
mysql_close($conn);
?>
