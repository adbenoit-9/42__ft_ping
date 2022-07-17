# FT_PING (@42Paris)
Recoding the ping command.

## Usage

```
$ git clone https://github.com/adbenoit-9/42_ft_ping.git
$ cd 42_ft_ping
$ make
$ ./ft_ping [options] <destination>
```

### Description

<p style="margin: 0px; margin-top: 1em; margin-bottom: 1.5em;margin-left: 1em">
    Send ICMP ECHO_REQUEST packets to network hosts.
</p>

### Options

<p style="margin: 0px; margin-top: 1em; margin-left: 1em">
    <strong>-c</strong> <ins>count</ins>
    <div style="margin-left: 3em; margin-top: 0px">
        Stop after sending count ECHO_REQUEST packets.
    </div>
</p>
<p style="margin: 0px; margin-left: 1em">
    <strong>-h</strong>
    <div style="margin-left: 3em; margin-top: 0px">
        Show help.
    </div>
</p>
<p style="margin: 0px; margin-left: 1em">
    <strong>-q</strong>
    <div style="margin-left: 3em; margin-top: 0px">
        Quiet output. Nothing is displayed except the summary lines at startup time and when finished.
    </div>
</p>
<p style="margin: 0px; margin-left: 1em">
    <strong>-t</strong> <ins>ttl</ins>
    <div style="margin-left: 3em; margin-top: 0px">
        Set the IP Time to Live.
    </div>
</p>
<p style="margin: 0px; margin-left: 1em">
    <strong>-v</strong>
    <div style="margin-left: 3em; margin-top: 0px">
        Verbose output.
    </div>
</p>

