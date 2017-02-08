var capitals = {
    USA: "Washington, D.C.", 
    Canada: "Ottawa", 
    Mexico: "Mexico City"
};

var form = document.getElementById("countryForm");
form.onsubmit = function () {
    // check if valid country selected
    if (form.country.value == "None") {
        alert("please select a country!");
    }
    else {
        var capital = capitals[form.country.value];
        alert("The capital of " + form.country.value + " is " + capital);
    }
    return false;
}