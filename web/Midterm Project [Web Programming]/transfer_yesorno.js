var transfer_money = document.getElementById('transfer_money')
var yes = document.getElementById('yes')
var no = document.getElementById('no')

transfer_money.innerHTML = localStorage.getItem('transfer_money')

yes.addEventListener('click',transfer_success)
no.addEventListener('click',back)


function transfer_success(){

    // If you press Yes, information will be contained in the date information,funds_in, funds_out, running_bal,
    // and this information will be available later in the account information.

    var now = new Date()

    var cur_bal = Number(localStorage.getItem('balance')) - Number(localStorage.getItem('transfer_money'))
    localStorage.setItem('balance',String(cur_bal))

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
    f_out.push(localStorage.getItem('transfer_money'))
    localStorage.setItem('funds_out',JSON.stringify(f_out))

    output = localStorage.getItem('running_bal')
    bal = JSON.parse(output)
    bal.push(localStorage.getItem('balance'))
    localStorage.setItem('running_bal',JSON.stringify(bal))


    var count = Number(localStorage.getItem('count'))
    count++
    localStorage.setItem('count',String(count))

 
    window.location.href = 'transfer_success.html'
}
function back(){
    window.location.href = 'transfer.html'
}