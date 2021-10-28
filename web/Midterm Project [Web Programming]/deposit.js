var deposit = document.getElementById('deposit')
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
var btn_dot = document.getElementById('btn_.')
var btn_ent = document.getElementById('btn_ent')
var btn_del = document.getElementById('btn_del')
var back = document.getElementById('back')

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
btn_dot.addEventListener('click',func_dot)
btn_ent.addEventListener('click',func_ent)
btn_del.addEventListener('click',func_del)
back.addEventListener('click',menu)

//All buttons write the corresponding letters in the account number when clicking.

function func0(){
    deposit.value = deposit.value + '0'
}
function func1(){
    deposit.value = deposit.value + '1'
}
function func2(){
    deposit.value = deposit.value + '2'
}
function func3(){
    deposit.value = deposit.value + '3'
}
function func4(){
    deposit.value = deposit.value + '4'
}
function func5(){
    deposit.value = deposit.value + '5'
}
function func6(){
    deposit.value = deposit.value + '6'
}
function func7(){
    deposit.value = deposit.value + '7'
}
function func8(){
    deposit.value = deposit.value + '8'
}
function func9(){
    deposit.value = deposit.value + '9'
}
function func_dot(){
    deposit.value = deposit.value + '.'
}
function func_del(){
    deposit.value = deposit.value.substring(0,deposit.value.length-1)
}
function func_ent(){    
    localStorage.setItem('deposit_money',deposit.value)
    window.location.href = 'deposit_yesorno.html'
}
function menu(){
    window.location.href = 'menu.html'
}