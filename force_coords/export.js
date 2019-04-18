function getCoords() {
     var nodes = graph.graph.nodes();
     var txt = JSON.stringify(nodes);
     var recipe =  window.open('','ResultWindow','width=600,height=600');
       var html = '<html><head><title>Result Window</title></head><body><div>' + txt + '</div></body></html>';
   recipe.document.open();
   recipe.document.write(html);
   recipe.document.close();
}
