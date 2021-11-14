var home = document.getElementById('home')
var another = document.getElementById('another')
var ret = document.getElementById('return')


home.addEventListener('click',go_menu)
another.addEventListener('click',another_withdraw)
ret.addEventListener('click',init)



function go_menu(){ //go menu
    window.location.href = 'menu.html'
}

function another_withdraw(){ // withdraw again
    window.location.href = 'withdraw.html'
}

function init(){ //go first page
    window.location.href = 'Intro.html'
}
