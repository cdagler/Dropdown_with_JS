document.write('\
\
<div class="container">\
	<h3>Here Are Some Dropdowns</h3>\
	<button type="button" class="btn btn-link" data-toggle="collapse" data-target="#collapse_button_1"><b><i style="font-size:70%;" class="glyphicon glyphicon-chevron-down"></i> List 1</b></button>\
	<div id="collapse_button_1" class="collapse">\
		<ol>\
			<li>Sub List 1-A</li>\
			<li>Sub List 1-B</li>\
			<ul>\
				<li>SubList 1.B-1</li>\
				<li>SubList 1.B-1</li>\
			</ul>\
			<li>Sub List 1-C</li>\
		</ol>\
	</div>\
	<br>\
	<button type="button" class="btn btn-link" data-toggle="collapse" data-target="#collapse_button_2"><b><i style="font-size:70%;" class="glyphicon glyphicon-chevron-down"></i>  List 2</b></button>\
	<div id="collapse_button_2" class="collapse">\
		<ol>\
			<li>Sub List 2-A</li>\
			<ul>\
				<li>Sub List 2.A-1</li>\
			</ul>\
			<li>Sub List 2-B</li>\
			<ul>\
				<li>Sub List 2.B-1</li>\
			</ul>\
			<li>Sub List 2-C</li>\
			<ul>\
				<li>Sub List 2.C-1</li>\
				<li>Sub List 2.C-2</li>\
				<li>Sub List 2.C-3</li>\
			</ul>\
		</ol>\
	</div>\
	<br>\
	<button type="button" class="btn btn-link" data-toggle="collapse" data-target="#collapse_button_3"><b><i style="font-size:70%;" class="glyphicon glyphicon-chevron-down"></i>  List 3</b></button>\
	<div id="collapse_button_3" class="collapse">\
		<ol>\
			<li>Sub List 3-A</li>\
			<li>Sub List 3-B</li>\
			<li>Sub List 3-C</li>\
			<li>Sub List 3-D</li>\
			<li>Sub List 3-E</li>\
		</ol>\
	</div>\
</div>\
\
');
