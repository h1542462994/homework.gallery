
/* functions */
function validateUser(username, password){
/*
    if (!(username instanceof String && password instanceof  String)){
        throw new TypeError("username and password should be String instance.")
    }
*/

    if (username.length === 0) {
        return "用户名不能为空"
    } else if(username.length > 6){
        return "用户名长度不能超过6位"
    }

    if (password.length === 0) {
        return "密码不能为空"
    } else if (password.length > 6){
        return "密码长度不能超过6位"
    }

    return true /* pass validation */
}

function onLoginClick(clickHandle = 0){
    let username = document.querySelector("input[name='username']").value /* get input data */
    let password = document.querySelector("input[name='password']").value
    console.log(`before login:\t username= ${username} password = ${password}`)
    let validateResult = validateUser(username, password) /* validate */
    if (validateResult === true){
        return true
    }

    alert(validateResult) /* show the validation result. */

    return false
}

/*
window.onload += () => {
    let loginForm = window.find("#login")
    loginForm.addEventListener('submit', onLoginClick)
}*/
