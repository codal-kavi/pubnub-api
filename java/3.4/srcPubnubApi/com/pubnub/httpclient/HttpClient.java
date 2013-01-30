package com.pubnub.httpclient;

import java.io.IOException;
import java.util.Hashtable;
import com.pubnub.api.PubnubException;

public abstract class HttpClient {

	public static HttpClient getClient() {
			return new HttpClientCore();
	}

	public HttpClient getClient(int requestTimeout, int connTimeout) {
		return new HttpClientCore(requestTimeout, connTimeout);
	}
	
	public HttpClient getClient(int requestTimeout) {
		return new HttpClientCore(requestTimeout);
	}
	
	public synchronized HttpClient reset() {
		int connTimeout = getConnectionTimeout();
		int requestTimeout = getRequestTimeout();
		shutdown();
		return getClient(requestTimeout, connTimeout);
		
	}
	public abstract int getRequestTimeout();

	public abstract void setRequestTimeout(int requestTimeout);

	public abstract int getConnectionTimeout();

	public abstract void setConnectionTimeout(int connectionTimeout);

	public abstract void abortCurrentRequest();
	
	public abstract boolean isRedirect(int rc);

	public abstract boolean checkResponse(int rc);

	public abstract boolean isOk(int rc);
	
	public abstract void shutdown();

	public abstract  HttpResponse fetch(String url) throws IOException, PubnubException;

	public abstract HttpResponse fetch(String url, Hashtable headers)
			throws IOException, PubnubException;
}