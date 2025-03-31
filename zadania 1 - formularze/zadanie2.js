const input_km = document.getElementById("km");
const input_gdansk = document.getElementById("gdansk");
const output_p = document.getElementById("output");

function calculate_price(){
    let output;
    let price;
    if(input_gdansk.checked == true){
        output = "Dowieziemy Twoją pizze za darmo.";
    }else{
        price = input_km.value * 2;
        output = `Dowóz będzie Cię kosztował ${price} złotych`;
    }
    output_p.textContent = output;
}

input_km.addEventListener("input", calculate_price);
input_gdansk.addEventListener("input", calculate_price);