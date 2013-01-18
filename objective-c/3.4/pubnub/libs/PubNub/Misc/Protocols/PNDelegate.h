//
//  PNDelegate.h
//  pubnub
//
//  Describes interface which is used to organize
//  communication between user code and PubNub
//  client instance.
//
//
//  Created by Sergey Mamontov on 12/5/12.
//
//


#pragma mark Class forward

@class PubNub, PNError, PNMessage;


@protocol PNDelegate <NSObject>

@optional

/**
 * Called on delegate when some client runtime error occurred
 * (mostly because of configuration/connection when connected)
 */
- (void)pubnubClient:(PubNub *)client error:(PNError *)error;

/**
 * Called on delegate when client is about to initiate connection
 * to the origin
 */
- (void)pubnubClient:(PubNub *)client willConnectToOrigin:(NSString *)origin;

/**
 * Called on delegate when client successfully connected to the
 * origin and perfomed initial calls (time token requests to make
 * connection keep-alive)
 */
- (void)pubnubClient:(PubNub *)client didConnectToOrigin:(NSString *)origin;

/**
 * Called on delegate when client disconnected from PubNub services
 * and ready for new session
 */
- (void)pubnubClient:(PubNub *)client didDisconnectFromOrigin:(NSString *)origin;

/**
 * Called on delegate when client disconnected from PubNub services
 * because of error
 */
- (void)pubnubClient:(PubNub *)client didDisconnectFromOrigin:(NSString *)origin withError:(PNError *)error;

/**
 * Called on delegate when come error occurred during PubNub client
 * connection session and it will be closed
 */
- (void)pubnubClient:(PubNub *)client willDisconnectWithError:(PNError *)error;

/**
 * Called on delegate when occurred error while tried to connect
 * to PubNub services
 * error - returned error will contain information about origin
 *         host name and error code which caused this error
 */
- (void)pubnubClient:(PubNub *)client connectionDidFailWithError:(PNError *)error;

/**
 * Called on delegate when client successfully subscribed to specified
 * set of channels
 */
- (void)pubnubClient:(PubNub *)client didSubscribeOnChannels:(NSArray *)channels;

/**
 * Called on delegate when some kind of error occurred during 
 * subscription creation
 * error - returned error will contain information about channel
 *         on which this error occurred and possible reason of error
 */
- (void)pubnubClient:(PubNub *)client subscriptionDidFailWithError:(PNError *)error;

/**
 * Called on delegate when client successfully unsubscribed from specified
 * set of channels
 */
- (void)pubnubClient:(PubNub *)client didUnsubscribeOnChannels:(NSArray *)channels;

/**
 * Called on delegate when some kind of error occurred during
 * unsubscribe
 * error - returned error will contain information about channel
 *         on which this error occurred and possible reason of error
 */
- (void)pubnubClient:(PubNub *)client unsubscriptionDidFailWithError:(PNError *)error;

/**
 * Called on delegate when PubNub client retrieved time
 * token from PubNub service
 */
- (void)pubnubClient:(PubNub *)client didReceiveTimeToken:(NSNumber *)timeToken;

/**
 * Called on delegate when PubNub client failed to
 * retrieve time token from PubNub service because
 * of some error
 */
- (void)pubnubClient:(PubNub *)client timeTokenReceiveDidFailWithError:(PNError *)error;

/**
 * Called on delegate when PubNub client is about to send
 * message to remote server
 */
- (void)pubnubClient:(PubNub *)client willSendMessage:(PNMessage *)message;

/**
 * Called on delegate when some kind of error occurred while
 * tried to send message to PubNub services
 */
- (void)pubnubClient:(PubNub *)client didFailMessageSend:(PNMessage *)message withError:(PNError *)error;

/**
 * Called on delegate when message was successfully set to
 * the PubNub service
 */
- (void)pubnubClient:(PubNub *)client didSendMessage:(PNMessage *)message;


#pragma mark - Configuration override delegate methods

/**
 * This method allow to override value passed in configuration
 * during client initalization.
 * This method called when service reachabilty reported that 
 * service are available and previous session is failed because
 * of network error or even not launched.
 * We can change client configuration, but it will trigger 
 * client hard reset (if connected)
 */
- (NSNumber *)shouldReconnectPubNubClient:(PubNub *)client;

@end
