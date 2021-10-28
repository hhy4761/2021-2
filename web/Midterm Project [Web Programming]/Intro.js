var account_number = document.getElementById('account_number')
var btn_1 = document.getElementById('btn_1')
var btn_2 = document.getElementById('btn_2')
var btn_3 = document.getElementById('btn_3')
var btn_4 = document.getElementById('btn_4')
var btn_5 = document.getElementById('btn_5')
var btn_6 = document.getElementById('btn_6')
var btn_7 = document.getElementById('btn_7')
var btn_8 = document.getElementById('btn_8')
var btn_9 = document.getElementById('btn_9')
var btn_0 = document.getElementById('btn_0')
var btn_ent = document.getElementById('btn_ent')
var btn_del = document.getElementById('btn_del')

var date = new Array()
var funds_in = new Array()
var funds_out = new Array()
var balance = new Array()

localStorage.setItem('balance','2000')
localStorage.setItem('count','0')
localStorage.setItem('date',JSON.stringify(date));
localStorage.setItem('funds_in',JSON.stringify(funds_in));
localStorage.setItem('funds_out',JSON.stringify(funds_out));
localStorage.setItem('running_bal',JSON.stringify(balance));

btn_1.addEventListener('click',func1)
btn_2.addEventListener('click',func2)
btn_3.addEventListener('click',func3)
btn_4.addEventListener('click',func4)
btn_5.addEventListener('click',func5)
btn_6.addEventListener('click',func6)
btn_7.addEventListener('click',func7)
btn_8.addEventListener('click',func8)
btn_9.addEventListener('click',func9)
btn_0.addEventListener('click',func0)
btn_ent.addEventListener('click',func_ent)
btn_del.addEventListener('click',func_del)

//All buttons write the corresponding letters in the account number when clicking.

function func0(){
    account_number.value = account_number.value + '0'
}
function func1(){
    account_number.value = account_number.value + '1'
}
function func2(){
    account_number.value = account_number.value + '2'
}
function func3(){
    account_number.value = account_number.value + '3'
}
function func4(){
    account_number.value = account_number.value + '4'
}
function func5(){
    account_number.value = account_number.value + '5'
}
function func6(){
    account_number.value = account_number.value + '6'
}
function func7(){
    account_number.value = account_number.value + '7'
}
function func8(){
    account_number.value = account_number.value + '8'
}
function func9(){
    account_number.value = account_number.value + '9'
}
function func_del(){
    account_number.value = account_number.value.substring(0,account_number.value.length-1)
}
function func_ent(){
    if(account_number.value == '1234567890123456') {
        window.location.href = 'pin.html';
    }
    else{
        alert('That account number does not exist!')
    }
}
