import bb.cascades 1.0

Sheet 
{
    id: sheet
    peekEnabled: true
    
    Page 
    {
        titleBar: TitleBar 
        {
            title: "About"
            dismissAction: ActionItem 
            {
                title: "Close"
                onTriggered: 
                {
                    sheet.close();
                }
            }
        }
        
        ScrollView 
        {
            Container 
            {
                topPadding: 20
                leftPadding: 20
                rightPadding: 20
                bottomPadding: 20
                
                Header 
                {
                    title: "About The App"
                }
                
                ImageView 
                {
                    preferredWidth: 300
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/icon.png"
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                Label 
                {
                    text: "A great tool to use to make useful stuffs with your Camera's Flash"
                    multiline: true
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                Header 
                {
                    title: "About The Developer"
                }
                
                ImageView 
                {
                    preferredWidth: 300
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/me.jpg"
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                Label 
                {
                    text: "Name: Oliver Martinez"
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                Label 
                {
                    text: "Email: nemoryoliver@gmail.com"
                    textStyle.color: Color.Cyan
                    horizontalAlignment: HorizontalAlignment.Center
                    onTouch: 
                    {
                        if (event.isUp())
                        {
                            _app.invokeEmail("nemoryoliver@gmail.com", "Support : " + appname, "How may we help you?\n\n")
                        }
                    }
                }
                
                Label 
                {
                    textStyle.color: Color.Cyan
                    text: "Website: http://nemoryoliver.com"
                    horizontalAlignment: HorizontalAlignment.Center
                    onTouch: 
                    {
                        if (event.isUp())
                        {
                            _app.invokeBrowser("http://nemoryoliver.com");
                        }
                    }
                }
            }
        }
    }
}