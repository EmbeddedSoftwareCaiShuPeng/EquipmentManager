$(document).ready(function(){
	init();
});

function init(){
	var temp = "";
	//初始化表格标题。
	temp+="<tr class='lead'><td>器材id</td><td>器材名</td><td>器材类型</td><td>器材状态</td></tr>";
	$("#tbody").append(temp);
	//获取数据并添加。
	$.ajax({
    url: "/getEquipment/",
    dataType: "json",
		type:"GET",
    data:"{}",
    success: function(data) {
    	for(var i = 0; i < data.length; i++) {
    		temp = "<tr><td>"+data[i].pk
              +"</td><td>"+data[i].fields.name
              +"</td><td>"+data[i].fields.type
              +"</td><td>"+data[i].fields.state
              +"</td></tr>";
        $("#tbody").append(temp);
    	}
    },
    error: function(XMLHttpRequest, textStatus, errorThrown) {//请求失败处理函数
      alert(XMLHttpRequest.status);
      alert(XMLHttpRequest.readyState);
      alert(textStatus);
      alert('请求失败');
    }
	});
}