var pin_number = document.getElementById('pin_number')
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
var back = document.getElementById('back')
var cnt = 5

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
back.addEventListener('click',init)

//All buttons write the corresponding letters in the account number when clicking.

function func0(){
    pin_number.value = pin_number.value + '0'
}
function func1(){
    pin_number.value = pin_number.value + '1'
}
function func2(){
    pin_number.value = pin_number.value + '2'
}
function func3(){
    pin_number.value = pin_number.value + '3'
}
function func4(){
    pin_number.value = pin_number.value + '4'
}
function func5(){
    pin_number.value = pin_number.value + '5'
}
function func6(){
    pin_number.value = pin_number.value + '6'
}
function func7(){
    pin_number.value = pin_number.value + '7'
}
function func8(){
    pin_number.value = pin_number.value + '8'
}
function func9(){
    pin_number.value = pin_number.value + '9'
}
function func_del(){
    pin_number.value = pin_number.value.substring(0,pin_number.value.length-1)
}
function func_ent(){

    //Upon successful login, arrangements for date information, funds_in, funds_out, and running_bal are created,
    // and these information can be later deposited, withdrawn, and transfered so that you can check it in your account information.

    if(pin_number.value == '1234') {
        var now = new Date()

        var output = localStorage.getItem('date')
        var date = JSON.parse(output)
        date.push(now)
        localStorage.setItem('date',JSON.stringify(date))

        output = localStorage.getItem('funds_in')
        f_in = JSON.parse(output)
        f_in.push('0')
        localStorage.setItem('funds_in',JSON.stringify(f_in))

        output = localStorage.getItem('funds_out')
        f_out = JSON.parse(output)
        f_out.push('0')
        localStorage.setItem('funds_out',JSON.stringify(f_out))

        output = localStorage.getItem('running_bal')
        bal = JSON.parse(output)
        bal.push(localStorage.getItem('balance'))
        localStorage.setItem('running_bal',JSON.stringify(bal))


        var count = Number(localStorage.getItem('count'))
        count++
        localStorage.setItem('count',String(count))

        window.location.href = 'menu.html';
    }
    else{ //If the login fails, the cnt will be reduced one by one, and as soon as the cnt becomes 0, all buttons will not be used.
        cnt--
        if(cnt==0){
            pin_number.disabled = true
            btn_1.disabled = true
            btn_2.disabled = true
            btn_3.disabled = true
            btn_4.disabled = true
            btn_5.disabled = true
            btn_6.disabled = true
            btn_7.disabled = true
            btn_8.disabled = true
            btn_9.disabled = true
            btn_0.disabled = true
            btn_del.disabled = true
            btn_ent.disabled = true
        }
        alert('Incorrect PIN. You have '+cnt+' attemptsleft')
    }
}
function init(){
    window.location.href = 'Intro.html'
}