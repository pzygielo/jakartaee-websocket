/*
 * Copyright (c) 2025 Contributors to the Eclipse Foundation
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
 */
package com.sun.ts.tests.websocket.ee.jakarta.websocket.server.handshakerequest;

import java.io.IOException;

import com.sun.ts.tests.websocket.common.util.IOUtil;

import jakarta.websocket.OnError;
import jakarta.websocket.OnMessage;
import jakarta.websocket.Session;
import jakarta.websocket.server.ServerEndpoint;

@ServerEndpoint(value = "/getlocalhostname", configurator = GetLocalHostNameConfigurator.class)
public class WSCGetLocalHostNameServer {
	@OnMessage
	public String onMessage(String msg) {
		return msg;
	}

	@OnError
	public void onError(Session session, Throwable thr) throws IOException {
		thr.printStackTrace(); // Write to error log, too
		String message = IOUtil.printStackTrace(thr);
		session.getBasicRemote().sendText(message);
	}
}
