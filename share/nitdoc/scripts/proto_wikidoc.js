var state = false;

// SHA
var shaLastCommit;
var shaBaseTree;
var shaNewTree;
var shaNewCommit;
var shaBlob;

// User
var userB64 = null;
var currentTree;
var pathFile;
var recurTree = "";


$(document).ready(function() {
    loadContent();

    $('textarea').hide();
    $("fileContent").hide();

    $("ul").click(function(event) {   
        var id = event.target.id;

        $("ul li").each(function() {           
           if($(this).attr("id") == id){
                pathFile = $(this).attr("name");
           }
        }); 
        
        var url = "https://api.github.com/repos/StefanLage/test3/git/blobs/" + id;

        getFileContent(url);

    });

    
    // Open edit file
    $('.text_label').click(function(){
        $(this).hide();
        $("textarea").text($(this).text());
        $(this).next().show();
        $(this).next().select();
    });

    // Close editing
    $('textarea').blur(function() {
         if ($.trim(this.value) == ''){
             this.value = (this.defaultValue ? this.defaultValue : '');
         }
         else{
             $(this).prev().html(this.value);
         }
 
         $(this).hide();
         $(this).prev().show();
         //$(this).prev().prev().show();
    });


});


function loadContent()
{
    state = false;
    //getLastCommit();
    //getCurrentTree();

    //$("ul").empty();

    loadFile();
}

function loadFile()
{
    getLastCommit();
    getBlobsTree(shaBaseTree);
}


function getLastCommit() 
{
    userB64 = "Basic " + base64.encode($("#login").val()+':'+$("#password").val());

    $.ajax({
        beforeSend: function (xhr) { 
            if ($("#login").val() != ""){ 
                xhr.setRequestHeader ("Authorization", userB64);
            }
        },
        type: "GET",
        url: "https://api.github.com/repos/StefanLage/test3/git/refs/heads/master",
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
        url: "https://api.github.com/repos/StefanLage/test3/git/commits/" + shaLastCommit,
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
                //getCurrentTree();
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
        url: "https://api.github.com/repos/StefanLage/test3/git/trees", 
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
        url: "https://api.github.com/repos/StefanLage/test3/git/commits", 
        data:'{ "message" : "New commit", '+
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

function commit()
{
    $.ajax({ 
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "POST",
        url: "https://api.github.com/repos/StefanLage/test3/git/refs/heads/master", 
        data:'{ "sha" : "'+shaNewCommit+'", '+
                '"force" :"true"'+
             '}',

        success: function(success)
        {
            //loadContent();
            window.open(JSON.parse(success).object.url, '_blank');
            window.focus();
        }
    });
}


function setBlob()
{
    //alert($(".text_label").text());

    $.ajax({
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization",  userB64);
        },
        type: "POST", 
        url: "https://api.github.com/repos/StefanLage/test3/git/blobs", 
        data:'{ "content" : "'+$(".text_label").text().replace(/\r?\n/g, '\\n').replace(/\t/g, '\\t')+'", '+
                '"encoding" :"utf-8"'+
            '}',
        
        success: function(success)
        {
            //alert(success); 
            shaBlob = JSON.parse(success).sha;
            setNewTree();
        }
    });
}

/*
var t = false
function getCurrentTree()
{
    $.ajax({
        beforeSend: function (xhr) { 
            xhr.setRequestHeader ("Authorization", userB64);
        },
        type: "GET", 
        url: "https://api.github.com/repos/StefanLage/test3/git/trees/" + shaBaseTree, 

        success: function(success)
        {
            if(t == false){
                shaBaseTree = JSON.parse(success).tree[1].sha;
                t =true;
                getCurrentTree();
            }
            else{
                currentTree = JSON.parse(success).tree[0].url;
                getFileContent();
            }
        }
    });
}*/

// Display file content
function getFileContent(urlFile)
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
            //$("#fileContent").text(success);
            $('.text_label').text(success);
            state = true;
        }
    });
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
        url: "https://api.github.com/repos/StefanLage/test3/git/trees/" + tree, 
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

// Add file in UL
function addLi(blob, path)
{
    $(".menu ul").append('<li id="'+blob.sha+'" name="'+path+'"><a><span class="'+path+'" name="'+path+'" id="'+blob.sha+'">'+blob.path+'</span></a></li>');
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
