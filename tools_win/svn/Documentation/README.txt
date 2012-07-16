 ==============================
 WANdisco Subversion Read Me 
 Date:  17 June 2010  
 =============================


 Compatibility
 =============

 This software supports the following Windows versions:
 Windows XP          (32-bit and 64-bit)
 Windows Server 2003 (32-bit and 64-bit)
 Windows Server 2008 (64-bit)
 Windows Vista       (32-bit and 64-bit)
 Windows 7           (32-bit and 64-bit)


 Client
 ======

 For help with Subversion commands, please see the Subversion Book, this can be found here:
 http://svnbook.red-bean.com/nightly/en/index.html

 The Subversion Book may also be found in the .\Documentation\ directory named: subversion-book.pdf


 Server 
 ======
 
 Configuration notes
 -------------------
 
 During the installation you are able to customise Apache HTTPD to work as a Subversion server. 
 For help with installing the product, please see the Installation.txt  file located in the .\Documentation\ directory.

 Post installation, you may configure Apache options via the configuration file in .\Apache2\conf\httpd.conf

 For Subversion server specific configuration options see .\Apache2\conf\subversion.conf

 For further information on configuring Apache HTTPD with Subversion see the Subversion book located here:
 http://svnbook.red-bean.com/nightly/en/svn.ref.mod_dav_svn.conf.html

 You need to restart the service to apply changes after editing any of the the Apache HTTPD configuration files.

 Runtime Notes
 -------------

 The recommended way to Start/Stop/Restart the Subversion Server is to use the "Server Control" program. 
 This can be found post-installation within the "WANdisco Subversion" start menu entry under the "Server" folder.

 The "Server Control" program will place an icon in the Windows task bar that you may use to control the Subversion Server.

 
 Getting Help 
 ============

 To report bugs or to request a feature, please e-mail opensource@wandisco.com
 This e-mail address should NOT be used for support requests, if you have a support contract with us, please raise a ticket.

 If you need professional support with your Subversion implementation, we have a range of competitive support contracts  available, please see:
 http://wandisco.com/products/svn/support.php 
 
 For community help, please post on our forums located at: http://subversion.wandisco.com 

 EOF