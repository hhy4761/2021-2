var cur_balance = document.getElementById('balance')
var back = document.getElementById('back')
var tbody = document.getElementById('table_body')
var output = localStorage.getItem('date')
var date_arr = JSON.parse(output)
var output = localStorage.getItem('funds_in')
var funds_in_arr = JSON.parse(output)
var output = localStorage.getItem('funds_out')
var funds_out_arr = JSON.parse(output)
var output = localStorage.getItem('running_bal')
var running_bal_arr = JSON.parse(output)

for(var i=0; i<Number(localStorage.getItem('count'));i++){ 
    var row = tbody.insertRow(tbody.rows.length)
    var date = row.insertCell(0)
    var funds_out = row.insertCell(1)
    var funds_in = row.insertCell(2)
    var running_bal = row.insertCell(3)
    date.innerHTML  = date_arr[i]
    funds_out.innerHTML  = funds_out_arr[i]
    funds_in.innerHTML  = funds_in_arr[i]
    running_bal.innerHTML  = running_bal_arr[i]
    // Write the date information, withdrawal, deposit, 
    // and information in the arrangement of the current amount on the table.
}
cur_balance.innerHTML = localStorage.getItem('balance')
back.addEventListener('click',menu)



function menu(){
    window.location.href = 'menu.html'
}
