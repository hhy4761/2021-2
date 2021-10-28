var transfer = document.getElementById('transfer_money')
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

function func0(){
    transfer.value = transfer.value + '0'
}
function func1(){
    transfer.value = transfer.value + '1'
}
function func2(){
    transfer.value = transfer.value + '2'
}
function func3(){
    transfer.value = transfer.value + '3'
}
function func4(){
    transfer.value = transfer.value + '4'
}
function func5(){
    transfer.value = transfer.value + '5'
}
function func6(){
    transfer.value = transfer.value + '6'
}
function func7(){
    transfer.value = transfer.value + '7'
}
function func8(){
    transfer.value = transfer.value + '8'
}
function func9(){
    transfer.value = transfer.value + '9'
}
function func_dot(){
    transfer.value = transfer.value + '.'
}
function func_del(){
    transfer.value = transfer.value.substring(0,transfer.value.length-1)
}
function func_ent(){    

    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    
    localStorage.setItem('transfer_money',transfer.value)
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('transfer_money'))
    if(check < 0){
        alert("You don't have enough money to transfer. Check your account.")
    }
    else
        window.location.href = 'transfer_yesorno.html'
}
function menu(){
    window.location.href = 'menu.html'
}