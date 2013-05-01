var state = false;

// SHA
var shaLastCommit;
var shaBaseTree;
var shaNewTree;
var shaNewCommit;
var shaBlob;
var shaMaster;

// User
var userB64 = null;
var currentTree;
var pathFile;
var recurTree = "";
var text = "";
var repoExist;
var branchName = "";
var githubRepo = "";
var branchExist = false;
var userName = "";
var password = "";
var commitMessage = "";
var preElement;
var updateComment;
var editComment = 0;
var commentLineStart;
var commentLineEnd;
var commentType;
var addNewComment = false;
var sessionStarted = false;

var opts = {
	  lines: 11, // The number of lines to draw
	  length: 7, // The length of each line
	  width: 4, // The line thickness
	  radius: 10, // The radius of the inner circle
	  corners: 1, // Corner roundness (0..1)
	  rotate: 0, // The rotation offset
	  color: '#FFF', // #rgb or #rrggbb
	  speed: 1, // Rounds per second
	  trail: 60, // Afterglow percentage
	  shadow: false, // Whether to render a shadow
	  hwaccel: false, // Whether to use hardware acceleration
	  className: 'spinner', // The CSS class to assign to the spinner
	  zIndex: 99999, // The z-index (defaults to 2000000000)
	  top: '300', // Top position relative to parent in px
	  left: 'auto' // Left position relative to parent in px
	};
var targetSpinner = document.getElementById('waitCommit');
var	spinner = new Spinner(opts).spin(targetSpinner);


/*
* JQuery Case Insensitive :icontains selector
*/
$.expr[':'].icontains = function(obj, index, meta, stack){
	return (obj.textContent.replace(/\[[0-9]+\]/g, "") || obj.innerText.replace(/\[[0-9]+\]/g, "") || jQuery(obj).text().replace(/\[[0-9]+\]/g, "") || '').toLowerCase().indexOf(meta[3].toLowerCase()) >= 0;
};

/*
 *	Quick Search global vars
 */
 
// Current search results preview table
var currentTable = null;

//Hightlighted index in search result preview table
var currentIndex = -1;

window.onbeforeunload = function() {
	if(editComment > 0){
    	return 'Are you sure you want to navigate away from this page?';
	}
};


/*
* Add folding and filtering facilities to class description page.
*/
$(document).ready(function() {
	
	/*
	* Highlight the spoted element
	*/
	highlightBlock(currentAnchor());

	/*
	* Nav block folding
	*/
	
	// Menu nav folding
	$(".menu nav h3")
	.prepend(
		$(document.createElement("a"))
		.html("-")
		.addClass("fold")
	)
	.css("cursor", "pointer")
	.click( function() {
			if($(this).find("a.fold").html() == "+") {
				$(this).find("a.fold").html("-");
			} else {
				$(this).find("a.fold").html("+");
			}
			$(this).nextAll().toggle();
	})
	
	// Insert search field
	$("nav.main ul")
	.append(
		$(document.createElement("li"))
		.append(
			$(document.createElement("form"))
			.append(
				$(document.createElement("input"))
				.attr({
					id: "search",
					type:	"text",
					autocomplete: "off",
					value: "quick search..."
				})
				.addClass("notUsed")

				// Key management
				.keyup(function(e) {
					switch(e.keyCode) {

						// Select previous result on "Up"
						case 38:
							// If already on first result, focus search input
							if(currentIndex == 0) {
								$("#search").val($(currentTable.find("tr")[currentIndex]).data("searchDetails").name);
								$("#search").focus();
							// Else select previous result
							} else if(currentIndex > 0) {
								$(currentTable.find("tr")[currentIndex]).removeClass("activeSearchResult");
								currentIndex--;
								$(currentTable.find("tr")[currentIndex]).addClass("activeSearchResult");
								$("#search").val($(currentTable.find("tr")[currentIndex]).data("searchDetails").name);
								$("#search").focus();
							}
						break;

						// Select next result on "Down"
						case 40:
							if(currentIndex < currentTable.find("tr").length - 1) {
								$(currentTable.find("tr")[currentIndex]).removeClass("activeSearchResult");
								currentIndex++;
								$(currentTable.find("tr")[currentIndex]).addClass("activeSearchResult");
								$("#search").val($(currentTable.find("tr")[currentIndex]).data("searchDetails").name);
								$("#search").focus();
							}
						break;
						// Go to url on "Enter"
						case 13:
							if(currentIndex > -1) {
								window.location = $(currentTable.find("tr")[currentIndex]).data("searchDetails").url;
								return false;
							}
							if($("#search").val().length == 0)
								return false
				
							window.location = "full-index.html#q=" + $("#search").val();
							if(window.location.href.indexOf("full-index.html") > -1) {
								location.reload();
							}				
							return false;
						break;

						// Hide results preview on "Escape"
						case 27:
							$(this).blur();
							if(currentTable != null) {
								currentTable.remove();
								currentTable = null;
							}
						break;

						default:
							if($("#search").val().length == 0) {
								return false;
							}
						
							// Remove previous table
							if(currentTable != null) {
								currentTable.remove();
							}

							// Build results table
							currentIndex = -1;
							currentTable = $(document.createElement("table"));

							// Escape regexp related characters in query
							var query = $("#search").val();
							query = query.replace(/\[/gi, "\\[");
							query = query.replace(/\|/gi, "\\|");
							query = query.replace(/\*/gi, "\\*");
							query = query.replace(/\+/gi, "\\+");
							query = query.replace(/\\/gi, "\\\\");
							query = query.replace(/\?/gi, "\\?");
							query = query.replace(/\(/gi, "\\(");
							query = query.replace(/\)/gi, "\\)");

							var index = 0;
							var regexp = new RegExp("^" + query, "i");
							for(var entry in entries) {
								if(index > 10) {
									break;
								}
								var result = entry.match(regexp);
								if(result != null && result.toString().toUpperCase() == $("#search").val().toUpperCase()) {
									for(var i = 0; i < entries[entry].length; i++) {
										if(index > 10) {
											break;
										}
										currentTable.append(
											$(document.createElement("tr"))
											.data("searchDetails", {name: entry, url: entries[entry][i]["url"]})
											.data("index", index)
											.append($(document.createElement("td")).html(entry))
											.append(
												$(document.createElement("td"))
													.addClass("entryInfo")
													.html(entries[entry][i]["txt"] + "&nbsp;&raquo;"))
											.mouseover( function() {
												$(currentTable.find("tr")[currentIndex]).removeClass("activeSearchResult");
												$(this).addClass("activeSearchResult");
												currentIndex = $(this).data("index");
											})
											.mouseout( function() {
												$(this).removeClass("activeSearchResult");
											 })
											.click( function() {
												window.location = $(this).data("searchDetails")["url"];
											})
										);
										index++;
									}
								}
							}
							
							// Initialize table properties
							currentTable.attr("id", "searchTable");
							currentTable.css("position", "absolute");
							currentTable.width($("#search").outerWidth());
							$("header").append(currentTable);
							currentTable.offset({left: $("#search").offset().left + ($("#search").outerWidth() - currentTable.outerWidth()), top: $("#search").offset().top + $("#search").outerHeight()});

							// Preselect first entry
							if(currentTable.find("tr").length > 0) {
								currentIndex = 0;
								$(currentTable.find("tr")[currentIndex]).addClass("activeSearchResult");
								$("#search").focus();
							}
						break;
					}
				})
				.focusout(function() {
					if($(this).val() == "") {
						$(this).addClass("notUsed");
						$(this).val("quick search...");
					}
				})
				.focusin(function() {
					if($(this).val() == "quick search...") {
						$(this).removeClass("notUsed");
						$(this).val("");
					}
				})
			)
			.submit( function() {
				return false;
			})
		)
	 );

	 // Close quicksearch list on click
	 $(document).click(function(e) {
		if(e.target != $("#search")[0] && e.target != $("#searchTable")[0]) {
			if(currentTable != null) {
				currentTable.remove();
				currentTable = null;
			}
		}
	 });
	
	// Insert filter field
	$("article.filterable h2, nav.filterable h3")
	.after(
		$(document.createElement("div"))
		.addClass("filter")
		.append(
			$(document.createElement("input"))
			.attr({
				type:	"text",
				value:	"filter..."
			})
			.addClass("notUsed")
			.keyup(function() {
				$(this).parent().parent().find("ul li:not(:icontains('" + $(this).val() + "'))").addClass("hide");
				$(this).parent().parent().find("ul li:icontains('" + $(this).val() + "')").removeClass("hide");
			})
			.focusout(function() {
				if($(this).val() == "") {
					$(this).addClass("notUsed");
					$(this).val("filter...");
				}
			})
			.focusin(function() {
				if($(this).val() == "filter...") {
					$(this).removeClass("notUsed");
					$(this).val("");
				}
			})
		)
	);
	
	// Filter toggle between H I R in nav porperties list
	$("nav.properties.filterable .filter")
	.append(
		$(document.createElement("a"))
		.html("H")
		.attr({
			title:	"hide inherited properties"
		})
		.click( function() {
			if($(this).hasClass("hidden")) {
				$(this).parent().parent().find("li.inherit").show();
			} else {
				$(this).parent().parent().find("li.inherit").hide();
			}
			
			$(this).toggleClass("hidden");
		})
	)
	.append(
		$(document.createElement("a"))
		.html("R")
		.attr({
			title:	"hide redefined properties"
		})
		.click( function() {
			if($(this).hasClass("hidden")) {
				$(this).parent().parent().find("li.redef").show();
			} else {
				$(this).parent().parent().find("li.redef").hide();
			}
			
			$(this).toggleClass("hidden");
		})
	)
	.append(
		$(document.createElement("a"))
		.html("I")
		.attr({
			title:	"hide introduced properties"
		})
		.click( function() {
			if($(this).hasClass("hidden")) {
				$(this).parent().parent().find("li.intro").show();
			} else {
				$(this).parent().parent().find("li.intro").hide();
			}
			
			$(this).toggleClass("hidden");
		})
	);
	
	// Filter toggle between I R in 
	$("article.properties.filterable .filter, article.classes.filterable .filter")
	.append(
		$(document.createElement("a"))
		.html("I")
		.attr({
			title:	"hide introduced properties"
		})
		.click( function() {
			if($(this).hasClass("hidden")) {
				$(this).parent().parent().find("li.intro").show();
			} else {
				$(this).parent().parent().find("li.intro").hide();
			}
			
			$(this).toggleClass("hidden");
		})
	)
	.append(
		$(document.createElement("a"))
		.html("R")
		.attr({
			title:	"hide redefined properties"
		})
		.click( function() {
			if($(this).hasClass("hidden")) {
				$(this).parent().parent().find("li.redef").show();
			} else {
				$(this).parent().parent().find("li.redef").hide();
			}
			
			$(this).toggleClass("hidden");
		})
	);

	/*
	* Anchors jumps
	*/
	$("a[href*='#']").click( function() {
		highlightBlock($(this).attr("href").split(/#/)[1]);
	});
	
	//Preload filter fields with query string
	preloadFilters();

	



	/*  Proto TestWikiDoc */

	var Arrays = new Array();
	$('textarea').hide();
	$('a[id=commitBtn]').hide();
	$('a[id=cancelBtn]').hide();
	$(".popover").hide();

	$.when(getCommentLastCommit($('pre[class=text_label]').attr('tag'))).done(function(){		
		$('pre[class=text_label]').each(function(){
			getCommentOfFunction($(this));
		});
	});

	// Cancel creating branch
	$('#btnCancelBranch').click(function(){
		editComment -= 1;
   	 	$('#modalQuestion').hide();
   	 	$('#fade , #modal').fadeOut(function() {
			$('#fade, a.close').remove();  
		});
   	 	//$('textarea').hide();
   	 	//$('textarea').prev().show();
		stop();
   	});

	// Create new branch and continu
   	$('#btnCreateBranch').click(function(){
   	 	$('#modalQuestion').hide();

   	 	if($('#btnCreateBranch').text() != 'Ok'){
	   	 	// Create the branch
	   	 	createBranch();
   	 		commitMessage = $('#commitMessage').val();
			if(commitMessage == ""){ commitMessage = "New commit"; }
			if(userName != "" && password != ""){	
				if ($.trim(updateComment) == ''){ this.value = (this.defaultValue ? this.defaultValue : ''); }
		     	else{ startCommitProcess(); }
		    }
		}
		else
		{
			$('#fade , #modalQuestion, #modal').fadeOut(function() {
				$('#fade, a.close').remove();  
			});
		}
		//$('textarea').hide();
		//$('textarea').prev().show();
   	});

	// Open edit file
   	$('pre[class=text_label]').click(function(){
   			// the customer is loggued ?
			if(sessionStarted == false || userName == ""){
				// No => nothing happen
				return;
			}
			else{
   			var arrayNew = $(this).text().split('\n');	
			var lNew = arrayNew.length - 1;
			var adapt = "";

			for (var i = 0; i < lNew; i++) {
		        adapt += arrayNew[i];		     
		    	if(i < lNew-1){ adapt += "\n"; }
		    }

   			editComment += 1;
   			// hide comment
        	$(this).hide();
        	// Show edit box 
        	$(this).next().show();
        	// Show cancel button
        	$(this).next().next().show();  
        	// Show commit button
        	$(this).next().next().next().show();
        	// Add text in edit box      
        	if($(this).next().val() == ""){ $(this).next().val(adapt); }
        	// Resize edit box 
    		$(this).next().height($(this).next().prop("scrollHeight"));
    		// Select it
        	$(this).next().select();
        	preElement = $(this);   
    	}  
    });

   	 $('a[id=cancelBtn]').click(function(){
   	 	if(editComment > 0){ editComment -= 1; }
   	 	// Hide itself
   	 	$(this).hide();
   	 	// Hide commitBtn
   	 	$(this).next().hide();
   	 	// Hide Textarea
   	 	$(this).prev().hide();
   	 	// Show comment
   	 	$(this).prev().prev().show();
   	 });

   	 $('a[id=commitBtn]').click(function(){   	 	
		updateComment = $(this).prev().prev().val();
		commentType = $(this).prev().prev().prev().attr('type');

		if(updateComment == ""){ displayMessage('The comment field is empty!', 40, 45); }
		else{
			/*if (checkCookie() == true)
			{
				  	$('#login').hide();
				  	$('#password').hide();
				  	$('#password2').hide();				  	
				  	$('#logerName').hide();
				  	$('#logginName').text("Logged as " + userName );
				  	$('#logginName').show();
				  	$('#repoCommit2').css({'margin-top' : '20px'});
				  	$("#btnGitHub").text("Commit");
				  	sessionStarted = true;

			}
			else
			{
					sessionStarted = false;

			}*/

			if(sessionStarted == false){
				displayMessage("You need to be loggued before commit something", 45, 40);
				displayLogginModal();				
				return;
			}

			$('#repoCommit').val($('#repoName').attr('name'));
	  		$('#branchName').val('wikidoc');
	  		$('#commitMessage').val('New commit');  		
	  		pathFile = $(this).prev().prev().prev().attr('tag');	
			$('#modal').show().prepend('<a class="close"><img src="resources/icons/close.png" class="btn_close" title="Close" alt="Close" /></a>');			 
			$('body').append('<div id="fade"></div>');		
			$('#fade').css({'filter' : 'alpha(opacity=80)'}).fadeIn();
	   	 	//$(this).next().hide();
		}

		// Hide itself
	    //$(this).hide();
	    // Hide cancelBtn
	   	//$(this).prev().hide();
	   	// Hide Edit field
	   	//$(this).prev().prev().hide();
	   	// Show comment
	   	//$(this).prev().prev().prev().show();
   	 });

	

   	 $('.btn_close').click(function(){
   	 	$(this).hide();
   	 	//$(this).prev().hide();
   	 	//$(this).prev().prev().show();
   	 	$(this).next().hide();
   	 	//$('textarea').hide();

   	 	if(editComment > 0){ editComment -= 1; }
   	 });


	//Close Popups and Fade Layer
	$('body').on('click', 'a.close, #fade', function() { // Au clic sur le body...
		if(editComment > 0){ editComment -= 1; }
		$('#fade , #modal').fadeOut(function() {
			$('#fade, a.close').remove();  
		});
		//$('textarea').hide();
		//$('textarea').prev().show();		
		$('#modalQuestion').hide();
	});

	$('#loginAction').click(function(){

		var text;
		var url;
		var line;
		// Look if the customer is logged
		if(sessionStarted == false){
			displayMessage("You need to be loggued before commit something", 100, 40);	
			$('.popover').show();
			return;
		}		
		else{ userB64 = "Basic " + getCookie("logginNitdoc"); }

		githubRepo = $('#repoCommit').val();
		
		// Check if repo exist
		isRepoExisting();

		if(repoExist == true){
			branchName = $('#branchName').val();
			isBranchExisting();

			if(branchExist == true){
				
				editComment -= 1;
				commitMessage = $('#commitMessage').val();			
				if(commitMessage == ""){ commitMessage = "New commit";}

				if(sessionStarted == true){	
					if ($.trim(updateComment) == ''){ this.value = (this.defaultValue ? this.defaultValue : ''); }
			     	else{ startCommitProcess(); }
			     }	
			     $('#modal, #modalQuestion').fadeOut(function() {
					$('#login').val("");
					$('#password').val(""); 
					$('textarea').hide();
					$('textarea').prev().show();
					displaySpinner();
				});
			    $('a[id=cancelBtn]').hide();
   	 			$('a[id=commitBtn]').hide();
			}	
		 }
		 else{ editComment -= 1; }	
	});

	$('a[class=newComment]').click(function(){
   	 	addNewComment = true;
   	 	//alert("toto");
   	 	editComment += 1;
   		// hide comment
        $(this).hide();
        // Show edit box 
        $(this).next().show();
        // Show cancel button
        $(this).next().next().show();  
        // Show commit button
        $(this).next().next().next().show();        	        
        // Resize edit box 
    	$(this).next().height($(this).next().prop("scrollHeight"));
    	// Select it
        $(this).next().select();
        preElement = $(this);  
   	 });

	// Sign In an github user or Log out him
	$("#signIn").click(function(){
		if(sessionStarted == false){
			if($('#loginGit').val() == "" || $('#passwordGit').val() == ""){ displayMessage('The comment field is empty!', 40, 45); }
			else
			{
				userName = $('#loginGit').val();
				password = $('#passwordGit').val();
				userB64 = "Basic " +  base64.encode(userName+':'+password);
				setCookie("logginNitdoc", base64.encode(userName+':'+password), 1);				
				$('#loginGit').val("");
				$('#passwordGit').val("");
			}
		}	
		else
		{
			// Delete cookie and reset settings
			del_cookie("logginNitdoc");
		}	
		displayLogginModal();

	});

	// popover demo
    $("#logGitHub").click(function(){    	
    	displayLogginModal();
    }); 
    
    updateDisplaying();
    

/*
	//var toto = 'https://api.github.com/repos/StefanLage/WikiDoc/git/blobs/47dcfea9a3848cfbb9d2dbbd7e1cf0f0fc1979bb';
	//var toto = "https://api.github.com/repos/StefanLage/WikiDoc/git/blobs/5da68da6f5388abc66593570f17ac2dfe5c50bb2";
	commentLineStart = 341;
	commentLineEnd = 353;
	//getFileContent(toto, "test");
	//getCommentLastCommit();

	$('pre[class=text_label]').each(function(){
		//alert($(this).text());
		getCommentOfFunction($(this));
	});*/

});






/* Parse current URL and return anchor name */
function currentAnchor() {  
    var index = document.location.hash.indexOf("#");
    if (index >= 0) {
		return document.location.hash.substring(index + 1);
	}
	return null;
}

/* Prealod filters field using search query */
function preloadFilters() {
	// Parse URL and get query string
	var search = currentAnchor();
	
	if(search == null || search.indexOf("q=") == -1)
		return;
		
	search = search.substring(2, search.length);	
	
	if(search == "" || search == "undefined")
		return;
	
	$(":text").val(search);
	$(".filter :text")
		.removeClass("notUsed")
		.trigger("keyup");

}

/* Hightlight the spoted block */
function highlightBlock(a) {
	if(a == undefined) {
		return;
	}

	$(".highlighted").removeClass("highlighted");
	
	var target = $("#" + a);
	
	if(target.is("article")) {
		target.parent().addClass("highlighted");
	}
	
	target.addClass("highlighted");
	target.show();
}



function displayMessage(msg, widthDiv, margModal){
	spinner.stop();
	//$('#waitCommit').hide();
	$('#modal').hide();
	$('#btnCreateBranch').css('margin-left',widthDiv + '%');
	$('#txtQuestion').text(msg);
	$('#btnCreateBranch').text("Ok");
	$('#btnCancelBranch').hide();
	$('#modalQuestion').css({'left' : margModal + '%'})
	$('#modalQuestion').show();
	$('#modalQuestion').show().prepend('<a class="close"><img src="resources/icons/close.png" class="btnCloseQuestion" title="Close" alt="Close" /></a>');
	$('body').append('<div id="fade"></div>');
	$('#fade').css({'filter' : 'alpha(opacity=80)'}).fadeIn();
}

function displaySpinner(){
	spinner.spin(targetSpinner);
	$("#waitCommit").show();
}

// Check if the repo already exist
function isRepoExisting(){
	$.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET", 
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo, 
        async:false,
        dataType:'json',

        success: function()
        {       
        	repoExist = true;	
        },
        error: function()
        {        	
        	displayMessage('Repo not found !', 35, 45);
        	repoExist = false;
        }
    });
}

// Check if the branch already exist
function isBranchExisting(){
	$.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET", 
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/refs/heads/"+branchName, 
        async:false,
        dataType:'json',
        success: function(){
        	branchExist = true;
        },
        error: function()
        {
        	branchExist = false;
        	editComment -= 1;
        	$('#modal').hide();
        	$('#txtQuestion').text("Are you sure you want to create that branch ?");
        	$('#btnCancelBranch').show();
        	$('#btnCreateBranch').text("Yes");
			$('#modalQuestion').show();
			$('#modalQuestion').show().prepend('<a class="close"><img src="resources/icons/close.png" class="btnCloseQuestion" title="Close" alt="Close" /></a>');
			$('body').append('<div id="fade"></div>');
			$('#fade').css({'filter' : 'alpha(opacity=80)'}).fadeIn();
        }
    });
}

function createBranch(){

	getMasterSha();

	$.ajax({ 
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "POST",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/refs", 
        data:'{ "ref" : "refs/heads/'+branchName+'",'+
        		'"sha" : "'+shaMaster+'"'+
            '}',
        success: function(){
        	return;
        },
        error: function(){
        	editComment -= 1;        	
        	displayMessage('Impossible to create the new branch : ' + branchName, 40, 40);
        }
    });
}

function getMasterSha() 
{
    $.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/refs/heads/master",
        dataType:"json",
        async: false,
        success: function(success)
        {
            shaMaster = success.object.sha;
        }
    });
}

function loadContent()
{
    state = false;
    loadFile();
}

function loadFile()
{
    getLastCommit();
    getBlobsTree(shaBaseTree);
}


function getLastCommit() 
{   
    $.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/refs/heads/"+branchName,
        dataType:"json",
        async: false,
        success: function(success)
        {
            shaLastCommit = success.object.sha;
            getBaseTree();
        }
    });
}

function getBaseTree()
{
    $.ajax({ 
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/commits/" + shaLastCommit,
        dataType:"json",
        async: false,
        success: function(success)
        {   
            shaBaseTree = success.tree.sha;
            if (state){
                setBlob();                
            }
            else
            {                
                return;
            }
        }
    });
}

function setNewTree()
{
    $.ajax({ 
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "POST",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/trees", 
        data:'{ "base_tree" : "'+shaBaseTree+'", '+
                '"tree":[{ '+
                    '"path":"'+ pathFile +'",'+
                    '"mode":"100644",'+
                    '"type":"blob",'+
                    '"sha": "'+ shaBlob +'"'+
                '}] '+
            '}',
        success: function(success)
        { // si l'appel a bien fonctionné
            shaNewTree = JSON.parse(success).sha;
            setNewCommit();
        }
    });
}

function setNewCommit()
{
    $.ajax({ 
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "POST",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/commits", 
        data:'{ "message" : "'+ commitMessage +'", '+
                '"parents" :"'+shaLastCommit+'",'+ 
                '"tree": "'+shaNewTree+'"'+
             '}',
        success: function(success)
        {
            shaNewCommit = JSON.parse(success).sha;
            commit();
        }
    });
}

//Create a commit
function commit()
{
    $.ajax({ 
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "POST",
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/refs/heads/"+branchName, 
        data:'{ "sha" : "'+shaNewCommit+'", '+
                '"force" :"true"'+
             '}',
        success: function(success)
        {         
            displayMessage('Commit created successfully', 40, 40);
        },
        error:function(error){        	
        	displayMessage('Error ' + JSON.parse(error).object.message, 40, 40);
        }
    });
}

// Create a blob
function setBlob()
{
    $.ajax({
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization",  userB64);	            
        },
        type: "POST", 
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/blobs", 
        data:'{ "content" : "'+text.replace(/\r?\n/g, '\\n').replace(/\t/g, '\\t').replace(/\"/g,'\\"')+'", '+
                '"encoding" :"utf-8"'+
            '}',
        success: function(success)
        {
            //alert(success); 
            shaBlob = JSON.parse(success).sha;
            setNewTree();
        },
        error:function(error){
        	displayMessage('Error : Problem parsing JSON', 40, 40);
        }
    });
}

// Display file content
function getFileContent(urlFile, newC)
{
    $.ajax({
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Accept",  "application/vnd.github-blob.raw");
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET", 
        url: urlFile, 
        async:false,
        success: function(success)
        {
            state = true;
            replaceComment(newC, success);
            //getCommentOfFunction(success);
        }
    });
}

function replaceComment(newC, fileContent){	
	var arrayNew = newC.split('\n');	
	var lNew = arrayNew.length;
	text = "";

    var lines = fileContent.split("\n");
	for (var i = 0; i < lines.length; i++) {
		if(i == commentLineStart){
			if(addNewComment == true){
        		for(var indexLine=0; indexLine < lines[i+1].length; indexxLine++){        			
        			if(lines[i+1].substr(indexLine,1) == "\t" || lines[i+1].substr(indexLine,1) == "#"){
        				text += lines[i+1].substr(indexLine,1);
        			}
        			else{
        				break;
        			}
        		}  
        		text += lines[i] + "\n";   		
        	}
        	else{
				// We change the comment
			    for(var j = 0; j < lNew; j++){
			    	if(commentType == 1){
			    		text += "\t# " + arrayNew[j] + "\n";
					}
	        		else{
	        			if(arrayNew[j] == ""){
	        				text += "#"+"\n";
	        			}
	        			else{
	        				text += "# " + arrayNew[j] + "\n";
	        			}        		
	        		}
	        	}
        	}
        }
        else if(i < commentLineStart || i >= commentLineEnd){
        	if(i == lines.length-1){
        		text += lines[i];
        	}
        	else{
        		text += lines[i] + "\n";
        	}
        }
    }
    if(addNewComment == true){
    	addNewComment = false;
    }
}

function getCommentOfFunction(element){
	var textC = "";
	//alert(element.attr("title"));
	var numL = element.attr("title");
	if(numL != null){		         		
		commentLineStart = numL.split('-')[0] - 1;
		commentLineEnd = (commentLineStart + element.text().split('\n').length) - 1;

	    var lines = currentfileContent.split("\n");
		for (var i = 0; i < lines.length; i++) {
			if(i >= commentLineStart-1 && i <= commentLineEnd){			
				if (lines[i].substr(1,1) == "#"){
					textC += lines[i].substr(3,lines[i].length) + "\n";
				}
				else if(lines[i].substr(0,1) == '#'){
					textC += lines[i].substr(2,lines[i].length) + "\n";
				}				
	        }
	    }    
	    if (textC != ""){
	    	element.text(textC);
	    }    	
	}	
}

// Get BLOBS of the Tree
function getBlobsTree(tree)
{
    $.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET", 
        url: "https://api.github.com/repos/"+userName+"/"+githubRepo+"/git/trees/" + tree, 
        async:false,
        dataType:'json',
        success: function(success)
        {   
            $(success.tree).each(function(index, object){
                
                if(object.mode == "040000"){
                    if(recurTree == ""){
                        recurTree = object.path + "/";
                    }
                    else{
                        recurTree += object.path;
                    }
                    getBlobsTree(object.sha);
                }
                else{
                    addLi(object, recurTree + object.path);
                } 
            })
            recurTree = "";
        }
    });
}

// Init process to commit the new comment
function startCommitProcess()
{
	var numL = preElement.attr("title");		         		
	commentLineStart = numL.split('-')[0] - 1;
	if(addNewComment == true){
		commentLineStart++;
	}
	commentLineEnd = (commentLineStart + preElement.text().split('\n').length) - 1;
	state = true;
	replaceComment(updateComment, currentfileContent);
	shaLastCommit = lastCommit;	
	getBaseTree();	
	editComment = false;
}

var lastCommit = "";
var currentfileContent = "";
function getLastCommit2() 
{   
    $.ajax({
        type: "GET",
        url: "https://api.github.com/repos/StefanLage/WikiDoc/git/refs/heads/wikidoc",
        dataType:"json",
        async: false,
        success: function(success)
        {
        	lastCommit = success.object.sha; 
        }
    });
}

function getCommentLastCommit(path){	

	getLastCommit2();

	$.ajax({  
		/*beforeSend: function (xhr) {             
        	xhr.setRequestHeader ("Connection", "keep-alive");            
        }, */
        type: "GET",
        //url: "https://rawgithub.com/StefanLage/WikiDoc/" + lastCommit + "/lib/standard/collection/array.nit",
        url: "https://rawgithub.com/StefanLage/WikiDoc/" + lastCommit + "/" + path,
        //dataType:"json",
        async: false,
        success: function(success)
        {
        	//return success.object.sha; 
        	//alert(success);            	  
        	currentfileContent = success;   
        }
    });
}

function displayLogginModal(){
	if ($('.popover').is(':hidden')) {		
		$('.popover').show();
	}
	else {
		$('.popover').hide();
	}
	updateDisplaying();
}

function updateDisplaying(){
	if (checkCookie() == true)
	{
	  	$('#loginGit').hide();
	  	$('#passwordGit').hide();
	  	$('#lbpasswordGit').hide();		
	  	$('#lbloginGit').hide();	  			  		 
	  	$("#liGitHub").attr("class", "current");
	  	$("#imgGitHub").attr("src", "resources/icons/github-white.png");
	  	$('#nickName').text(userName);	  	
	  	$('#githubAccount').attr("href", "https://github.com/"+userName);
	  	$('#logginMessage').css({'display' : 'block'});
	  	$('#logginMessage').css({'text-align' : 'center'});	
	  	$('.popover').css({'height' : '80px'});	
	  	$('#signIn').text("Sign out");	
	  	sessionStarted = true;
	}
	else
	{
		sessionStarted = false;
		$('#logginMessage').css({'display' : 'none'});
		$("#liGitHub").attr("class", "");
	  	$("#imgGitHub").attr("src", "resources/icons/github-black.png");
	  	$('#loginGit').val("");
		$('#passwordGit').val("");
		$('#nickName').text("");
  		$('.popover').css({'height' : '160px'});	
  		$('#logginMessage').css({'display' : 'none'});
		$('#loginGit').show();
	  	$('#passwordGit').show();
	  	$('#lbpasswordGit').show();
	  	$('#lbloginGit').show();			  		
	  	$('#signIn').text("Sign In");
	}
}

function setCookie(c_name, value, exdays)
{
	var exdate=new Date();
	exdate.setDate(exdate.getDate() + exdays);
	var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
	document.cookie=c_name + "=" + c_value;
}

function del_cookie(c_name)
{
    document.cookie = c_name + '=; expires=Thu, 01 Jan 1970 00:00:01 GMT;';
}

function getCookie(c_name)
{
	var c_value = document.cookie;
	var c_start = c_value.indexOf(" " + c_name + "=");
	if (c_start == -1)
	  {
	  c_start = c_value.indexOf(c_name + "=");
	  }
	if (c_start == -1)
	  {
	  c_value = null;
	  }
	else
	  {
	  c_start = c_value.indexOf("=", c_start) + 1;
	  var c_end = c_value.indexOf(";", c_start);
	  if (c_end == -1)
	  {
	c_end = c_value.length;
	}
	c_value = unescape(c_value.substring(c_start,c_end));
	}
	return c_value;
}

function checkCookie()
{
	var username=getCookie("logginNitdoc");
	if (username!=null && username!="")
	{
		userName = base64.decode(username).split(':')[0];	  	
	  	return true;
	}
	else
	{
		return false;
	}
}



base64 = {};
base64.PADCHAR = '=';
base64.ALPHA = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
base64.getbyte64 = function(s,i) {
    // This is oddly fast, except on Chrome/V8.
    //  Minimal or no improvement in performance by using a
    //   object with properties mapping chars to value (eg. 'A': 0)
    var idx = base64.ALPHA.indexOf(s.charAt(i));
    if (idx == -1) {
    throw "Cannot decode base64";
    }
    return idx;
}

base64.decode = function(s) {
    // convert to string
    s = "" + s;
    var getbyte64 = base64.getbyte64;
    var pads, i, b10;
    var imax = s.length
    if (imax == 0) {
        return s;
    }

    if (imax % 4 != 0) {
    throw "Cannot decode base64";
    }

    pads = 0
    if (s.charAt(imax -1) == base64.PADCHAR) {
        pads = 1;
        if (s.charAt(imax -2) == base64.PADCHAR) {
            pads = 2;
        }
        // either way, we want to ignore this last block
        imax -= 4;
    }

    var x = [];
    for (i = 0; i < imax; i += 4) {
        b10 = (getbyte64(s,i) << 18) | (getbyte64(s,i+1) << 12) |
            (getbyte64(s,i+2) << 6) | getbyte64(s,i+3);
        x.push(String.fromCharCode(b10 >> 16, (b10 >> 8) & 0xff, b10 & 0xff));
    }

    switch (pads) {
    case 1:
        b10 = (getbyte64(s,i) << 18) | (getbyte64(s,i+1) << 12) | (getbyte64(s,i+2) << 6)
        x.push(String.fromCharCode(b10 >> 16, (b10 >> 8) & 0xff));
        break;
    case 2:
        b10 = (getbyte64(s,i) << 18) | (getbyte64(s,i+1) << 12);
        x.push(String.fromCharCode(b10 >> 16));
        break;
    }
    return x.join('');
}

base64.getbyte = function(s,i) {
    var x = s.charCodeAt(i);
    if (x > 255) {
        throw "INVALID_CHARACTER_ERR: DOM Exception 5";
    }
    return x;
}


base64.encode = function(s) {
    if (arguments.length != 1) {
    throw "SyntaxError: Not enough arguments";
    }
    var padchar = base64.PADCHAR;
    var alpha   = base64.ALPHA;
    var getbyte = base64.getbyte;

    var i, b10;
    var x = [];

    // convert to string
    s = "" + s;

    var imax = s.length - s.length % 3;

    if (s.length == 0) {
        return s;
    }
    for (i = 0; i < imax; i += 3) {
        b10 = (getbyte(s,i) << 16) | (getbyte(s,i+1) << 8) | getbyte(s,i+2);
        x.push(alpha.charAt(b10 >> 18));
        x.push(alpha.charAt((b10 >> 12) & 0x3F));
        x.push(alpha.charAt((b10 >> 6) & 0x3f));
        x.push(alpha.charAt(b10 & 0x3f));
    }
    switch (s.length - imax) {
    case 1:
        b10 = getbyte(s,i) << 16;
        x.push(alpha.charAt(b10 >> 18) + alpha.charAt((b10 >> 12) & 0x3F) +
               padchar + padchar);
        break;
    case 2:
        b10 = (getbyte(s,i) << 16) | (getbyte(s,i+1) << 8);
        x.push(alpha.charAt(b10 >> 18) + alpha.charAt((b10 >> 12) & 0x3F) +
               alpha.charAt((b10 >> 6) & 0x3f) + padchar);
        break;
    }
    return x.join('');
}

$.fn.spin = function(opts) {
  this.each(function() {
    var $this = $(this),
        data = $this.data();

    if (data.spinner) {
      data.spinner.stop();
      delete data.spinner;
    }
    if (opts !== false) {
      data.spinner = new Spinner($.extend({color: $this.css('color')}, opts)).spin(this);
    }
  });
  return this;
};

