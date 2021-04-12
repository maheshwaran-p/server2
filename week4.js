Boolean = true;
function onClickHandler() {


    Boolean = !Boolean;



    if (Boolean == true) {
        document.getElementById("demo").innerHTML = "$00.00";
        document.getElementById("demo2").innerHTML = "$00.00";
    }
    else {
        var value2 = document.getElementById("dept").value;
        var val3 = value2 * 30

        document.getElementById("demo").innerHTML = "$30.00";

        document.getElementById("demo2").innerHTML = " Total  :$" + val3 + ".00";

    }
}

function phonenumber(phoneno) {

    var phoneno = /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;


}
function ValidateEmail(mail) {
    if (/^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/.test(myForm.emailAddr.value)) {
        return (true)
    }
    alert("You have entered an invalid email address!")
    return (false)
}

function myFunction() {
    var username = document.getElementById("username").value;
    var dept = document.getElementById("dept").value;
    var year = document.getElementById("year").value;
    var sem = document.getElementById("sem").value;
    var accountholdername = document.getElementById("accountholdername").value;
    var accountnumber = document.getElementById("accountnumber").value;
    var bankname = document.getElementById("mail").value;
    var branch = document.getElementById("phoneno").value;
    var ifsc = document.getElementById("ifsc").value;
    var micr = document.getElementById("micr").value;





    var x = document.getElementById("snackbar");
    if (username != '' && bankname != '' && dept != '' && year != '' && sem != '' && accountholdername != '' && accountnumber != '' && branch != '' && ifsc != '' && micr != '' && fileName != '' && fileName2 != '' && fileName3 != '' && fileName4 != '' && fileName5 != '' && fileName6 != '' && fileName7 != '' && fileName8 != ' ' && fileName9 != '' && fileName11 != '' && fileName12 != '' && fileName13 != '' && fileName14 != '' && fileName15 != ' ' && fileName16 != '' && fileName17 != '') {
        x.className = "show";
        setTimeout(function () { x.className = x.className.replace("show", ""); }, 9000);
        // location.replace("https://mahesh.newsled.in")
    }

}