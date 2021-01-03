<%@ page import="cn.edu.zjut.ejb.EJBFactory" %>
<%@ page import="javax.naming.NamingException" %>
<%@ page import="java.util.List" %>
<%@ page import="cn.edu.zjut.ejb.ProductCartRemote" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>myCart</title>
</head>
<body>
<%
    try {
        ProductCartRemote cart = (ProductCartRemote) session.getAttribute("cart");
        EJBFactory ejbFactory = new EJBFactory();
        ejbFactory.configure();
        if (cart == null) {

            cart = (ProductCartRemote) ejbFactory.getBean(ProductCartRemote.class.getName(), "ProductCartBean", true);
            session.setAttribute("cart", cart);

        } else {
            String productName = request.getParameter("product");
            String sPrice = request.getParameter("price");
            int price = 0;
            if (sPrice != null) price = Integer.parseInt(sPrice);
            cart.addProduct(productName, price);
            List<String> myProducts = cart.listProducts();
            out.println("Total Price:" + cart.totalPrice() + "<br>");
            out.println("My Products: <br>" + myProducts);
        }
    } catch (NamingException e) {
        e.printStackTrace();
    }
%>
<table style="border: 1px black">
    <tr>
        <td>
            <a href="myCart.jsp?product=fridge&price=3000">fridge buy</a>
        </td>
        <td>
    </tr>
    <tr>
        <td>
            <a href="myCart.jsp?product=ledtv&price=5000">ledtv buy</a>
        </td>
    </tr>
    <tr>
        <td>
            <a href="myCart.jsp?product=waterheater&price=2800">waterheater buy</a>
        </td>
    </tr>
    <tr>
        <td>
            <a href="myCart.jsp?product=car&price=300000">car buy</a>
        </td>
    </tr>
</table>
</body>
</html>
