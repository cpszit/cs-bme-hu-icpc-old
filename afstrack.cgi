var T=Math.random();
var Ref=document.referrer;
if (typeof(parent.document)!="unknown")
{
var F=parent.document.URL;
if (document.referrer==F) Ref=parent.document.referrer;
}
var S="usr="+AFS_Account+"P"+AFS_Tracker+"&js=1";
if (typeof AFS_Page == "undefined") var AFS_Page="unknown";
if (typeof AFS_Url == "undefined") var AFS_Url="unknown";
if (AFS_Page=="DetectName") {AFS_Page=document.title;}
if (AFS_Url=="DetectUrl") {AFS_Url=window.document.URL;}
S+="&title="+escape(AFS_Page);
S+="&url="+escape(AFS_Url);
S+="&refer="+escape(Ref);
if(typeof(screen)=="object")
{
S+="&resolution="+screen.width+"x"+screen.height;
S+="&color="+screen.colorDepth;
}
S+="&Tips="+T;
document.write("<a href='http://top.addfreestats.com/cgi-bin/main.cgi?usr="+AFS_Account+"' target='_blank'>");
document.write("<img border=0 src='http://"+AFS_Server+".addfreestats.com/cgi-bin/connect.cgi?");
document.write(S);
document.write("' border=0 height=49 width=90 title='AddFreeStats.com Free Web Stats'></a>");
document.write("<a href='http://www.addfreestats.com'></a>");
