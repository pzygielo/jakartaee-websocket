///////////////////////////////////////////////////////////////////////////////

    Copyright (c) 2020, 2024 Oracle and/or its affiliates. All rights reserved.

    This program and the accompanying materials are made available under the
    terms of the Eclipse Public License v. 2.0, which is available at
    http://www.eclipse.org/legal/epl-2.0.

    This Source Code may also be made available under the following Secondary
    Licenses when the conditions for such availability set forth in the
    Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
    version 2 with the GNU Classpath Exception, which is available at
    https://www.gnu.org/software/classpath/license.html.

    SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
NOTE TO WRITERS:
The following sections should be customized for the technology.
This text was originally from the JAX-RS TCK.  Most references
to JAX-RS have been parameterized to serve as a simple starting
point for customization.  There are still many details that will
need to be changed or removed.  The major sections 4.1, 4.2, and
4.3 should be preserved.  If their titles are changed, the links
at the top of config.adoc will need to be changed as well as well
as toc.adoc.
///////////////////////////////////////////////////////////////////////

[[GBFVU]][[configuring-your-environment-to-run-the-tck-against-the-reference-implementation]]

4.1 Configuring Your Environment to Run the TCK Against the Compatible Implementation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

After configuring your environment as described in this section,
continue with the instructions in link:using.html#GBFWO[Chapter 5, "Executing Tests."]


[NOTE]
=======================================================================

In these instructions, variables in angle brackets need to be expanded
for each platform. For example, `<JAVA_HOME>` becomes `$JAVA_HOME` on
Solaris/Linux and `%JAVA_HOME%` on Windows. In addition, the forward
slashes (`/`) used in all of the examples need to be replaced with
backslashes (`\`) for Windows. Finally, be sure to use the appropriate
separator for your operating system when specifying multiple path
entries (`;` on Windows, `:` on UNIX/Linux).

On Windows, you must escape any backslashes with an extra backslash in
path separators used in any of the following properties, or use forward
slashes as a path separator instead.

=======================================================================



1.  Set the following environment variables in your shell environment:
  a.  `JAVA_HOME` to the directory in which Java SE {SEversion} is installed
  b.  `M2_HOME` to the directory in which the Apache Maven build tool is installed.
  c.  +{TechnologyHomeEnv}+ to the directory in which the {TechnologyShortName}
  {TechnologyVersion} CI has been installed
  d.  `PATH` to include the following directories: `JAVA_HOME/bin`,
  and `M2_HOME/bin`
2.  Set the following System properties:
  a.  Set the `webServerHost` property to the name of the host on which
  Jakarta EE {JakartaEEVersion} CI is running. +
  The default setting is `localhost`.
  b.  Set the `webServerPort` property to the port number of the host on
  which Jakarta EE {JakartaEEVersion} CI is running. +
  The default setting is `8080`.
  c.  Set the `web.home` property to the installation directory of Jakarta EE
  {JakartaEEVersion} CI.
  d. Set the `porting.ts.url.class.1` property to your porting
  implementation class that is used for obtaining URLs. +
  The default setting for this property is
  `com.sun.ts.tests.websocket.lib.implementation.sun.common.SunRIURL`.
+
3. Set the below jars to the classpath 
  a. JAR file for the {TechnologyShortName} {TechnologyVersion} API. +
  eg.  `${web.home}/modules/jakarta.websocket-api.jar`.
  b. Arquillian JAR arquillian-junit5-container
  Maven cordinates :  
+
[source,oac_no_warn]
----
      <dependency>
            <groupId>org.jboss.arquillian.junit5</groupId>
            <artifactId>arquillian-junit5-container</artifactId>
            <version>1.7.0.Alpha10</version>
      </dependency>
----
+
  c. JUnit 5 jars (5.7.2+)
  Maven cordinates :
+
[source,oac_no_warn]
----
       <dependency>
          <groupId>org.junit</groupId>
          <artifactId>junit-bom</artifactId>
          <version>5.7.2</version>
          <type>pom</type>
          <scope>import</scope>
       </dependency>
----
+
 d. sigtest-maven-plugin (1.4) to run the signature tests.
  Maven cordinates :
+
[source,oac_no_warn]
----
      <dependency>
            <groupId>jakarta.tck</groupId>
            <artifactId>sigtest-maven-plugin</artifactId>
            <version>2.2</version>
        </dependency>
----
+
  e.  {TechnologyRI} CI jars +
  For eg, if you are using the {TechnologyRI} CI below jars need to be added to Classpath
 

+
[source,oac_no_warn]
----
${web.home}/modules/jakarta.websocket-api.jar
${web.home}/modules/jakarta.websocket-client-api.jar
${web.home}/modules/jakarta.servlet-api.jar
${web.home}/modules/jakarta.enterprise.cdi-api.jar
${web.home}/modules/tyrus-websocket-core.jar
${web.home}/modules/tyrus-client.jar
${web.home}/modules/tyrus-core.jar
${web.home}/modules/tyrus-container-grizzly.jar
${web.home}/modules/glassfish-grizzly-extra-all.jar
${web.home}/modules/nucleus-grizzly-all.jar
${web.home}/modules/tyrus-server.jar
${web.home}/modules/tyrus-container-servlet.jar
${web.home}/modules/tyrus-container-grizzly-client.jar
${web.home}/modules/tyrus-spi.jar
----
+
4.  Provide compatible implementation of the porting package interface
provided with the {TechnologyShortName} TCK. +
The porting package interface, `TSURLInterface.java`, obtains URL
strings for web resources in an implementation-specific manner. API
documentation for the `TSURLInterface.java` porting package interface is
available in the {TechnologyShortName} TCK documentation bundle.

[[GCLHU]][[configuring-your-environment-to-repackage-and-run-the-tck-against-the-vendor-implementation]]

4.2 Configuring Your Environment to Repackage and Run the TCK Against the Vendor Implementation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

After configuring your environment as described in this section,
continue with the instructions in link:using.html#GBFWO[Chapter 5, "Executing Tests."]


[NOTE]
=======================================================================

In these instructions, variables in angle brackets need to be expanded
for each platform. For example, `<JAVA_HOME>` becomes `$JAVA_HOME` on
Solaris/Linux and `%JAVA_HOME%` on Windows. In addition, the forward
slashes (`/`) used in all of the examples need to be replaced with
backslashes (`\`) for Windows. Finally, be sure to use the appropriate
separator for your operating system when specifying multiple path
entries (`;` on Windows, `:` on UNIX/Linux).

On Windows, you must escape any backslashes with an extra backslash in
path separators used in any of the following properties, or use forward
slashes as a path separator instead.

=======================================================================

[[sthref9]]

==== Before You Begin

Decide against which {TechnologyShortName} implementation the tests
will be run and determine to which Servlet–compliant Web server the
{TechnologyShortName} TCK applications will be published.


1.  Set the following environment variables in your shell environment:
  a.  `JAVA_HOME` to the directory in which Java SE {SEversion} is installed
  b.  `M2_HOME` to the directory in which the Apache Maven build tool is installed.
  c.  +{TechnologyHomeEnv}+ to the directory in which the {TechnologyShortName}
  {TechnologyVersion} CI has been installed
  d.  `PATH` to include the following directories: `JAVA_HOME/bin`,
  and `M2_HOME/bin`
2.  Set the following System properties:
  a.  Set the `webServerHost` property to the name of the host on which
  Jakarta EE {JakartaEEVersion} CI is running. +
  The default setting is `localhost`.
  b.  Set the `webServerPort` property to the port number of the host on
  which Jakarta EE {JakartaEEVersion} CI is running. +
  The default setting is `8080`.
  c.  Set the `web.home` property to the installation directory of Jakarta EE
  {JakartaEEVersion} CI.
  d. Set the `porting.ts.url.class.1` property to your porting
  implementation class that is used for obtaining URLs. +
  The default setting for this property is
  `com.sun.ts.lib.implementation.sun.common.SunRIURL`.
+
3. Set the below jars to the classpath 
  a. JAR file for the {TechnologyShortName} {TechnologyVersion} API. +
  eg.  `${web.home}/modules/jakarta.websocket-api.jar`.
  b. Arquillian JAR arquillian-junit5-container
  Maven cordinates :  
+
[source,oac_no_warn]
----
      <dependency>
            <groupId>org.jboss.arquillian.junit5</groupId>
            <artifactId>arquillian-junit5-container</artifactId>
            <version>1.7.0.Alpha10</version>
      </dependency>
----
+
  c. JUnit 5 jars (5.7.2+)
  Maven cordinates :
+
[source,oac_no_warn]
----
       <dependency>
          <groupId>org.junit</groupId>
          <artifactId>junit-bom</artifactId>
          <version>5.7.2</version>
          <type>pom</type>
          <scope>import</scope>
       </dependency>
----
+
  d.  {TechnologyRI} CI jars +
  For eg, if you are using the {TechnologyRI} CI below jars need to be added to Classpath

+
[source,oac_no_warn]
----
${web.home}/modules/jakarta.websocket-api.jar
${web.home}/modules/jakarta.websocket-client-api.jar
${web.home}/modules/jakarta.servlet-api.jar
${web.home}/modules/jakarta.enterprise.cdi-api.jar
${web.home}/modules/tyrus-websocket-core.jar
${web.home}/modules/tyrus-client.jar
${web.home}/modules/tyrus-core.jar
${web.home}/modules/tyrus-container-grizzly.jar
${web.home}/modules/glassfish-grizzly-extra-all.jar
${web.home}/modules/nucleus-grizzly-all.jar
${web.home}/modules/tyrus-server.jar
${web.home}/modules/tyrus-container-servlet.jar
${web.home}/modules/tyrus-container-grizzly-client.jar
${web.home}/modules/tyrus-spi.jar
----
+
4.  Provide compatible implementation of the porting package interface
provided with the {TechnologyShortName} TCK. +
The porting package interface, `TSURLInterface.java`, obtains URL
strings for web resources in an implementation-specific manner. API
documentation for the `TSURLInterface.java` porting package interface is
available in the {TechnologyShortName} TCK documentation bundle.


[[GCRWX]][[deploying-the-java-api-for-websocket-tck-tests]]

4.3 Deploying the Java API for WebSocket TCK Tests
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The {TechnologyShortName} TCK provides an automatic way of deploying
both archives to the configured web
container or containers by using arquillian Shrinkwrap API before the tests are run.

