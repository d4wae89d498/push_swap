<?php 


$list = [2, -10, 4, 7, 9];


var_dump($list);

$new_list = [$list[count($list) - 1]];
foreach($list as $l)
	$new_list[] = $l;


//$new_list[] = $list[0];

var_dump($new_list);

//$first_stage = [$new_list[0] - $new_list[1]];

//$first_stage = [$new_list[0] - $new_list[1]];

$i = 0;
while ($i < count($new_list) - 1)
{
	$first_stage[] = $new_list[$i + 1] - $new_list[$i];
	$i += 1;
}

var_dump($first_stage);

echo "_____\n";


$stages = [$first_stage];
$stage = 0;
while ($stage <= count($list))
{
	$i = 0;
	$new_stage = [];
	while ($i < (count($stages[$stage]) - 1))
	{
		$new_stage[] = $stages[$stage][$i + 1] - $stages[$stage][$i];
		$i += 1;
	}
	var_dump($new_stage);
	echo "__\n";
	$stages[] = $new_stage;
	$stage += 1;
}


exit(0);

$list_length = count($list);

$i = 0;
while ($i < $list_length)
{

	$i += 1;
}
