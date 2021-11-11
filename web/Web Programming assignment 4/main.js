$('.login_complete').addClass('hide')
$('.signup_complete').addClass('hide')
$('.signup').addClass('hide')
$('.box_container').addClass('hide')
$('#loginemail_box').addClass('hide')
$('#loginpassword_box').addClass('hide')
$('#login_val').addClass('hide')

$('#signup_btn').click(function(){
    $('.login').addClass('hide');
    $('.signup').removeClass('hide');
    $('.login_complete').addClass('hide')
    $('.signup_complete').addClass('hide')
    $('.box_container').removeClass('hide')
    $('.login_box_container').addClass('hide')
});

$('#login_btn').click(function(){
    $('.login').removeClass('hide')
    $('.signup').addClass('hide')
    $('.login_complete').addClass('hide')
    $('.signup_complete').addClass('hide')
    $('.login_box_container').removeClass('hide')
    $('.box_container').addClass('hide')
});

/* hide all component except first login component */

var check_firstname = false
var check_lastname = false
var check_sex = false
var check_email = false
var check_password = false
var check_password2 = false

$('#signup_submit').click(function(){ // I set a value of check_{}. If it's a false, you can't register as a membership. 
    // and if you success on signup, your data is saved in localstorage.


    if(check_firstname&&check_lastname&&check_sex&&check_email&&check_password&&check_password2){
        var signup_email = $('#signup_email').val()
        var signup_password = $('#signup_password').val()

        localStorage.setItem('email',signup_email)
        localStorage.setItem('password',signup_password)
        
        $('.login_complete').addClass('hide')
        $('.signup_complete').removeClass('hide')
        $('.signup').addClass('hide')
        $('.login').addClass('hide')
    }
    else{
        alert('You should complete signup')
    }

});

$('#login_submit').click(function(){ // get email and password from local storage. and check validation

    var login_email = $('#login_email').val()
    var login_password = $('#login_password').val()

    var email = localStorage.getItem('email')
    var pwd = localStorage.getItem('password')

    if(login_email == email && login_password == pwd){ 
        $('.login_complete').removeClass('hide')
        $('.signup_complete').addClass('hide')
        $('.signup').addClass('hide')
        $('.login').addClass('hide')
        $('.btn_container').addClass('hide')
    }

    else{
        $('#enter_msg').addClass('hide')
        $('#login_val').removeClass('hide')
    }

});

$('#signup_firstname').on("change keyup paste",function(){

    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, then you can obtain check_firstname true

    var val = $(this).val()
    $('#firstname_box').removeClass('hide')
    var getName= RegExp(/^[A-Z]+$/);
    var getNumber= RegExp(/^[a-zA-Z]+$/);
    if(!getName.test(val.charAt(0))){
        $('#firstname_box').removeClass('hide')
        $('#firstname_box').html('first name should start Capital letter')
        check_firstname = false
    }
    else if(!getNumber.test(val)){
        $('#firstname_box').removeClass('hide')
        $('#firstname_box').html('First name can contain only alphabet')
        check_firstname = false
    }
    else if(getNumber.test(val)){
        $('#firstname_box').addClass('hide')
        check_firstname = true
    }   
})

$('#signup_lastname').on("change keyup paste",function(){
    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, then you can obtain check_lastname true
    var val = $(this).val()
    $('#lastname_box').removeClass('hide')
    var getName= RegExp(/^[A-Z]+$/);
    var getNumber= RegExp(/^[a-zA-Z]+$/);
    if(!getName.test(val.charAt(0))){
        $('#lastname_box').removeClass('hide')
        $('#lastname_box').html('last name should start Capital letter')
        check_lastname = false
    }
    else if(!getNumber.test(val)){
        $('#lastname_box').removeClass('hide')
        $('#lastname_box').html('First name can contain only alphabet')
        check_lastname = false
    }
    else if(getNumber.test(val)){
        $('#lastname_box').addClass('hide')
        check_lastname = true
    }
})
$('input:radio[name=sex]').on("click",function(){
    // whenever you choose radio (name=sex), you can obatin check_sex true

    if($('input:radio[name=sex]').is(':checked') || $('input:radio[name=sex]').is(':checked')){
        $('#sex_box').addClass('hide')
        check_sex = true
    }    
})


$('#signup_email').on("change keyup paste",function(){
    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, then you can obtain check_email true

    var val = $(this).val()
    $('#email_box').removeClass('hide')

    var re = RegExp(/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/i);

    if(!re.test(val)){
        $('#email_box').removeClass('hide')
        $('#email_box').html('Your email address is invalid!')
        check_email = false
    }
    else if(re.test(val)){
         $('#email_box').addClass('hide')
         check_email = true
    }
})

$('#signup_password').on("change keyup paste",function(){
    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, then you can obtain check_password true
    var val = $(this).val()
    $('#password_box').removeClass('hide')

    var reg = RegExp(/^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{6,}$/);

    if(!reg.test(val)){
        $('#password_box').removeClass('hide')
        $('#password_box').html('Requirement: at least 6 character, one letter, one lowercase letter, at least one digit and one special character!')
        check_password = false
    }
    else if(reg.test(val)){
         $('#password_box').addClass('hide')
         check_password = true
    }
})

$('#signup_password2').on("change keyup paste",function(){
    // whenever change keyup paste, it will check whether your password is same with password2
    // and validation is ok, then you can obtain check_password2 true
    var val = $(this).val()
    $('#password2_box').removeClass('hide')

    var val2 = $('#signup_password').val()
    if(val!=val2){
        $('#password2_box').removeClass('hide')
        $('#password2_box').html('password does not match!')
        check_password2=false
    }
    else if(val==val2) {
        $('#password2_box').addClass('hide')
        check_password2 =true
    }
})

$('#login_email').on("focus",function(){
    $('#loginemail_box').removeClass('hide')
})

$('#login_email').on("change keyup paste",function(){
    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, there is no message of your email

    var val = $(this).val()
    $('#loginemail_box').removeClass('hide')

    var re = RegExp(/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/i);

    if(!re.test(val)){
        $('#loginemail_box').removeClass('hide')
        $('#loginemail_box').html('Your email address is invalid!')
    }
    else if(re.test(val)){
         $('#loginemail_box').addClass('hide')
    }
})

$('#login_password').on("change keyup paste",function(){
    // whenever change keyup paste, it will be checked input condition.
    // and If input validation is true, there is no message of your password
    var val = $(this).val()
    $('#loginpassword_box').removeClass('hide')

    if(val!=""){
        $('#loginpassword_box').addClass('hide')
    }
})