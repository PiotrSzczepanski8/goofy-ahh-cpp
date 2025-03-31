const input_ilosc = document.getElementById("ilosc");
const input_poprawiny = document.getElementById("poprawiny");
const output_p = document.getElementById("output");

function calculate_price(){
    price = input_ilosc.value * 100;
    if(input_poprawiny.checked == true){
        price = price * 13 / 10;
    }
    output_p.textContent = price;
}

input_ilosc.addEventListener("input", calculate_price);
input_poprawiny.addEventListener("input", calculate_price);