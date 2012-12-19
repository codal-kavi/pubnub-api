package main

import (
	"log"
	"pubnub"
)

func main() {
	pub := pubnub.PubnubInit("", "", "", "", false)
	channel := make(chan []byte)

	//start new goroutine  
	go pub.GetTime(channel)

	//receive from channel
	log.Printf("%s", <-channel)
}